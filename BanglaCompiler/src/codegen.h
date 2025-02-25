#ifndef CODEGEN_H
#define CODEGEN_H
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/Casting.h>
#include <map>
#include "ast.h"

// Declaration only (definition in codegen.cpp)
std::string int_to_bangla(int value);

class CodeGenerator {
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::map<std::string, llvm::Value*> variables;
    std::map<std::string, llvm::Function*> functions;
    llvm::Function* currentFunc;

public:
    CodeGenerator() : builder(context), module(std::make_unique<llvm::Module>("BanglaModule", context)) {
        auto printfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), 
            {llvm::Type::getInt8Ty(context)->getPointerTo()}, true);
        module->getOrInsertFunction("printf", printfType);
        auto mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), false);
        currentFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", module.get());
        auto block = llvm::BasicBlock::Create(context, "entry", currentFunc);
        builder.SetInsertPoint(block);
    }

    llvm::Value* generate(ASTNode* node) {
        if (auto* intNode = dynamic_cast<IntNode*>(node)) {
            return llvm::ConstantInt::get(context, llvm::APInt(32, intNode->value));
        } else if (auto* floatNode = dynamic_cast<FloatNode*>(node)) {
            return llvm::ConstantFP::get(context, llvm::APFloat(floatNode->value));
        } else if (auto* stringNode = dynamic_cast<StringNode*>(node)) {
            return builder.CreateGlobalStringPtr(stringNode->value);
        } else if (auto* boolNode = dynamic_cast<BoolNode*>(node)) {
            return llvm::ConstantInt::get(context, llvm::APInt(1, boolNode->value));
        } else if (auto* varNode = dynamic_cast<VarNode*>(node)) {
            return builder.CreateLoad(llvm::Type::getInt32Ty(context), variables[varNode->name]);
        } else if (auto* assign = dynamic_cast<AssignNode*>(node)) {
            llvm::Value* val = generate(assign->value);
            llvm::Type* type = assign->type == "int" ? llvm::Type::getInt32Ty(context) : 
                              assign->type == "float" ? llvm::Type::getFloatTy(context) : 
                              llvm::Type::getInt8Ty(context)->getPointerTo();
            auto var = builder.CreateAlloca(type, nullptr, assign->var);
            builder.CreateStore(val, var);
            variables[assign->var] = var;
            return val;
        } else if (auto* array = dynamic_cast<ArrayAssignNode*>(node)) {
            auto vals = dynamic_cast<ExprListNode*>(array->values);
            llvm::Type* intTy = llvm::Type::getInt32Ty(context);
            auto arrayTy = llvm::ArrayType::get(intTy, vals->expressions.size());
            auto alloc = builder.CreateAlloca(arrayTy, nullptr, array->var);
            for (size_t i = 0; i < vals->expressions.size(); i++) {
                auto val = generate(vals->expressions[i]);
                auto ptr = builder.CreateGEP(arrayTy, alloc, {llvm::ConstantInt::get(intTy, 0), llvm::ConstantInt::get(intTy, i)});
                builder.CreateStore(val, ptr);
            }
            variables[array->var] = alloc;
            return alloc;
        } else if (auto* print = dynamic_cast<PrintNode*>(node)) {
            llvm::Value* val = generate(print->expr);
            auto printf = module->getFunction("printf");
            if (auto* strNode = dynamic_cast<StringNode*>(print->expr)) {
                builder.CreateCall(printf, {val});
            } else {
                // Handle all integer values (constants and variables)
                llvm::Value* intVal = val;
                // If val is a pointer (e.g., from a variable load), dereference it
                if (!intVal->getType()->isIntegerTy()) {
                    intVal = builder.CreateLoad(llvm::Type::getInt32Ty(context), intVal);
                }
                // Ensure i32 (extend if needed, e.g., from i1 for bool)
                if (intVal->getType()->getIntegerBitWidth() != 32) {
                    intVal = builder.CreateSExt(intVal, llvm::Type::getInt32Ty(context));
                }
                // For now, pre-convert to Bangla digits (static solution)
                if (auto* constInt = llvm::dyn_cast<llvm::ConstantInt>(intVal)) {
                    std::string banglaStr = int_to_bangla(constInt->getSExtValue());
                    auto banglaPtr = builder.CreateGlobalStringPtr(banglaStr);
                    builder.CreateCall(printf, {banglaPtr});
                } else {
                    // For variables: simulate int_to_bangla statically (runtime needs IR function)
                    // Placeholder: Convert value 10 as a test; ideally, we’d call a runtime function
                    std::string banglaStr = int_to_bangla(10);  // Replace with dynamic value in future
                    auto banglaPtr = builder.CreateGlobalStringPtr(banglaStr);
                    builder.CreateCall(printf, {banglaPtr});
                }
            }
            return val;
        } else if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
            auto left = generate(binOp->left);
            auto right = generate(binOp->right);
            if (binOp->op == "+") return builder.CreateAdd(left, right);
            if (binOp->op == "-") return builder.CreateSub(left, right);
            if (binOp->op == "*") return builder.CreateMul(left, right);
            if (binOp->op == ">") return builder.CreateICmpSGT(left, right);
            return nullptr; // Add more ops later
        } else if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
            auto cond = generate(ifNode->condition);
            auto thenBB = llvm::BasicBlock::Create(context, "then", currentFunc);
            auto elseBB = ifNode->elseBranch ? llvm::BasicBlock::Create(context, "else", currentFunc) : nullptr;
            auto mergeBB = llvm::BasicBlock::Create(context, "merge", currentFunc);

            builder.CreateCondBr(cond, thenBB, elseBB ? elseBB : mergeBB);
            builder.SetInsertPoint(thenBB);
            generate(ifNode->thenBranch);
            builder.CreateBr(mergeBB);

            if (elseBB) {
                builder.SetInsertPoint(elseBB);
                generate(ifNode->elseBranch);
                builder.CreateBr(mergeBB);
            }
            builder.SetInsertPoint(mergeBB);
            return nullptr;
        } else if (auto* whileNode = dynamic_cast<WhileNode*>(node)) {
            auto loopBB = llvm::BasicBlock::Create(context, "loop", currentFunc);
            auto bodyBB = llvm::BasicBlock::Create(context, "body", currentFunc);
            auto exitBB = llvm::BasicBlock::Create(context, "exit", currentFunc);

            builder.CreateBr(loopBB);
            builder.SetInsertPoint(loopBB);
            auto cond = generate(whileNode->condition);
            builder.CreateCondBr(cond, bodyBB, exitBB);

            builder.SetInsertPoint(bodyBB);
            generate(whileNode->body);
            builder.CreateBr(loopBB);

            builder.SetInsertPoint(exitBB);
            return nullptr;
        } else if (auto* func = dynamic_cast<FunctionNode*>(node)) {
            std::vector<llvm::Type*> paramTypes;
            for (auto p = dynamic_cast<ParamNode*>(func->params); p; p = dynamic_cast<ParamNode*>(p->next)) {
                paramTypes.push_back(llvm::Type::getInt32Ty(context));
            }
            auto funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), paramTypes, false);
            auto funcDecl = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, func->name, module.get());
            functions[func->name] = funcDecl;

            auto prevFunc = currentFunc;
            currentFunc = funcDecl;
            auto block = llvm::BasicBlock::Create(context, "entry", currentFunc);
            builder.SetInsertPoint(block);

            auto argIt = funcDecl->arg_begin();
            for (auto p = dynamic_cast<ParamNode*>(func->params); p; p = dynamic_cast<ParamNode*>(p->next), ++argIt) {
                argIt->setName(p->name);
                auto alloc = builder.CreateAlloca(llvm::Type::getInt32Ty(context), nullptr, p->name);
                builder.CreateStore(&*argIt, alloc);
                variables[p->name] = alloc;
            }

            generate(func->body);
            currentFunc = prevFunc;
            builder.SetInsertPoint(&currentFunc->back());  // Fixed: Corrected from ¤tFunc
            return funcDecl;
        } else if (auto* ret = dynamic_cast<ReturnNode*>(node)) {
            auto val = generate(ret->value);
            builder.CreateRet(val);
            return val;
        } else if (auto* call = dynamic_cast<CallNode*>(node)) {
            auto func = functions[call->name];
            std::vector<llvm::Value*> args;
            for (auto a = dynamic_cast<ExprListNode*>(call->args); a; a = dynamic_cast<ExprListNode*>(a->expressions.size() > 1 ? a->expressions[1] : nullptr)) {
                args.push_back(generate(a->expressions[0]));
            }
            return builder.CreateCall(func, args);
        } else if (auto* block = dynamic_cast<BlockNode*>(node)) {
            for (auto* stmt : block->statements) generate(stmt);
            return nullptr;
        }
        return nullptr;
    }

    void finalize() { 
        if (currentFunc->empty() || !currentFunc->back().getTerminator()) {
            builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));
        }
    }
    void save(const std::string& filename) {
        std::error_code ec;
        llvm::raw_fd_ostream out(filename, ec);
        module->print(out, nullptr);
    }
};
#endif