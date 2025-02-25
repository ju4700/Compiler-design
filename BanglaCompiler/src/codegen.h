#ifndef CODEGEN_H
#define CODEGEN_H
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include "ast.h"

class CodeGenerator {
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::map<std::string, llvm::Value*> variables;
    llvm::Function* mainFunc;

public:
    CodeGenerator() : builder(context), module(std::make_unique<llvm::Module>("BanglaModule", context)) {
        auto printfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), 
            {llvm::Type::getInt8PtrTy(context)}, true);
        module->getOrInsertFunction("printf", printfType);
        auto mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), false);
        mainFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", module.get());
        auto block = llvm::BasicBlock::Create(context, "entry", mainFunc);
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
                              llvm::Type::getInt8PtrTy(context);
            auto var = builder.CreateAlloca(type, nullptr, assign->var);
            builder.CreateStore(val, var);
            variables[assign->var] = var;
            return val;
        } else if (auto* print = dynamic_cast<PrintNode*>(node)) {
            llvm::Value* val = generate(print->expr);
            auto printf = module->getFunction("printf");
            if (dynamic_cast<StringNode*>(print->expr)) {
                builder.CreateCall(printf, {val});
            } else {
                builder.CreateCall(printf, {builder.CreateGlobalStringPtr("%d\n"), val});
            }
            return val;
        } else if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
            auto left = generate(binOp->left);
            auto right = generate(binOp->right);
            if (binOp->op == "+") return builder.CreateAdd(left, right);
            if (binOp->op == "-") return builder.CreateSub(left, right);
            if (binOp->op == "*") return builder.CreateMul(left, right);
            if (binOp->op == ">") return builder.CreateICmpSGT(left, right);
            return nullptr; // Add more ops
        } else if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
            auto cond = generate(ifNode->condition);
            auto thenBB = llvm::BasicBlock::Create(context, "then", mainFunc);
            auto elseBB = ifNode->elseBranch ? llvm::BasicBlock::Create(context, "else", mainFunc) : nullptr;
            auto mergeBB = llvm::BasicBlock::Create(context, "merge", mainFunc);

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
        } else if (auto* block = dynamic_cast<BlockNode*>(node)) {
            for (auto* stmt : block->statements) generate(stmt);
            return nullptr;
        }
        return nullptr;
    }

    void finalize() { builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0))); }
    void save(const std::string& filename) {
        std::error_code ec;
        llvm::raw_fd_ostream out(filename, ec);
        module->print(out, nullptr);
    }
};
#endif