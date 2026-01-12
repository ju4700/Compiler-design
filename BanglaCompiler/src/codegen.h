#ifndef CODEGEN_H
#define CODEGEN_H
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/Casting.h>
#include <map>
#include "ast.h"

class CodeGenerator {
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::map<std::string, llvm::Value*> variables;
    std::map<std::string, llvm::Function*> functions;
    llvm::Function* currentFunc;
    llvm::Function* printBanglaFunc;

    // Create the runtime print_bangla function that converts int to Bangla digits
    void createPrintBanglaFunction() {
        // Declare printf
        auto printfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), 
            {llvm::Type::getInt8Ty(context)->getPointerTo()}, true);
        auto printfFunc = module->getOrInsertFunction("printf", printfType);

        // Create print_bangla(int value) function
        auto funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(context), 
            {llvm::Type::getInt32Ty(context)}, false);
        printBanglaFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, 
            "print_bangla", module.get());

        auto* entryBB = llvm::BasicBlock::Create(context, "entry", printBanglaFunc);
        auto* loopBB = llvm::BasicBlock::Create(context, "loop", printBanglaFunc);
        auto* printBB = llvm::BasicBlock::Create(context, "print", printBanglaFunc);
        auto* exitBB = llvm::BasicBlock::Create(context, "exit", printBanglaFunc);

        llvm::IRBuilder<> funcBuilder(context);
        funcBuilder.SetInsertPoint(entryBB);

        llvm::Value* inputVal = printBanglaFunc->arg_begin();
        
        // Bangla digits as global strings (০১২৩৪৫৬৭৮৯)
        std::vector<llvm::Value*> digitStrs;
        const char* banglaDigits[] = {"০", "১", "২", "৩", "৪", "৫", "৬", "৭", "৮", "৯"};
        for (int i = 0; i < 10; i++) {
            digitStrs.push_back(funcBuilder.CreateGlobalStringPtr(banglaDigits[i]));
        }

        // Handle zero case
        auto* isZero = funcBuilder.CreateICmpEQ(inputVal, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
        auto* zeroHandleBB = llvm::BasicBlock::Create(context, "zero_handle", printBanglaFunc);
        auto* nonZeroBB = llvm::BasicBlock::Create(context, "non_zero", printBanglaFunc);
        funcBuilder.CreateCondBr(isZero, zeroHandleBB, nonZeroBB);

        // Zero case: print "০" and return
        funcBuilder.SetInsertPoint(zeroHandleBB);
        funcBuilder.CreateCall(printfFunc, {digitStrs[0]});
        funcBuilder.CreateBr(exitBB);

        // Non-zero case: use simple recursive approach via stack
        funcBuilder.SetInsertPoint(nonZeroBB);
        
        // Allocate array for digits (max 10 digits for int32)
        auto* digitArray = funcBuilder.CreateAlloca(
            llvm::ArrayType::get(llvm::Type::getInt32Ty(context), 12), nullptr, "digits");
        auto* countPtr = funcBuilder.CreateAlloca(llvm::Type::getInt32Ty(context), nullptr, "count");
        funcBuilder.CreateStore(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0), countPtr);
        
        auto* valuePtr = funcBuilder.CreateAlloca(llvm::Type::getInt32Ty(context), nullptr, "value");
        
        // Handle negative: abs(value)
        auto* isNeg = funcBuilder.CreateICmpSLT(inputVal, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
        auto* absVal = funcBuilder.CreateSelect(isNeg, 
            funcBuilder.CreateNeg(inputVal), inputVal);
        funcBuilder.CreateStore(absVal, valuePtr);
        
        // Print minus sign if negative
        auto* minusStrBB = llvm::BasicBlock::Create(context, "minus_str", printBanglaFunc);
        auto* afterMinusBB = llvm::BasicBlock::Create(context, "after_minus", printBanglaFunc);
        funcBuilder.CreateCondBr(isNeg, minusStrBB, afterMinusBB);
        
        funcBuilder.SetInsertPoint(minusStrBB);
        auto* minusStr = funcBuilder.CreateGlobalStringPtr("-");
        funcBuilder.CreateCall(printfFunc, {minusStr});
        funcBuilder.CreateBr(afterMinusBB);
        
        funcBuilder.SetInsertPoint(afterMinusBB);
        funcBuilder.CreateBr(loopBB);

        // Loop: extract digits
        funcBuilder.SetInsertPoint(loopBB);
        auto* curVal = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), valuePtr);
        auto* isNotZero = funcBuilder.CreateICmpNE(curVal, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
        
        auto* extractBB = llvm::BasicBlock::Create(context, "extract", printBanglaFunc);
        funcBuilder.CreateCondBr(isNotZero, extractBB, printBB);

        // Extract digit
        funcBuilder.SetInsertPoint(extractBB);
        auto* curVal2 = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), valuePtr);
        auto* digit = funcBuilder.CreateSRem(curVal2, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 10));
        auto* newVal = funcBuilder.CreateSDiv(curVal2, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 10));
        funcBuilder.CreateStore(newVal, valuePtr);
        
        // Store digit in array
        auto* count = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), countPtr);
        auto* digitPtr = funcBuilder.CreateGEP(
            llvm::ArrayType::get(llvm::Type::getInt32Ty(context), 12), 
            digitArray, 
            {llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0), count});
        funcBuilder.CreateStore(digit, digitPtr);
        
        // Increment count
        auto* newCount = funcBuilder.CreateAdd(count, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1));
        funcBuilder.CreateStore(newCount, countPtr);
        
        funcBuilder.CreateBr(loopBB);

        // Print: reverse order
        funcBuilder.SetInsertPoint(printBB);
        auto* printLoopBB = llvm::BasicBlock::Create(context, "print_loop", printBanglaFunc);
        auto* printBodyBB = llvm::BasicBlock::Create(context, "print_body", printBanglaFunc);
        
        auto* idxPtr = funcBuilder.CreateAlloca(llvm::Type::getInt32Ty(context), nullptr, "idx");
        auto* finalCount = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), countPtr);
        auto* startIdx = funcBuilder.CreateSub(finalCount, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1));
        funcBuilder.CreateStore(startIdx, idxPtr);
        funcBuilder.CreateBr(printLoopBB);

        funcBuilder.SetInsertPoint(printLoopBB);
        auto* idx = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), idxPtr);
        auto* isValid = funcBuilder.CreateICmpSGE(idx, 
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
        funcBuilder.CreateCondBr(isValid, printBodyBB, exitBB);

        funcBuilder.SetInsertPoint(printBodyBB);
        auto* idx2 = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), idxPtr);
        auto* digitPtr2 = funcBuilder.CreateGEP(
            llvm::ArrayType::get(llvm::Type::getInt32Ty(context), 12), 
            digitArray, 
            {llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0), idx2});
        auto* digitVal = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), digitPtr2);
        
        // Switch on digit value to print correct Bangla digit
        auto* switchInst = funcBuilder.CreateSwitch(digitVal, exitBB, 10);
        for (int i = 0; i < 10; i++) {
            auto* caseBB = llvm::BasicBlock::Create(context, "case" + std::to_string(i), printBanglaFunc);
            switchInst->addCase(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), i), caseBB);
            funcBuilder.SetInsertPoint(caseBB);
            funcBuilder.CreateCall(printfFunc, {digitStrs[i]});
            auto* nextIdxBB = llvm::BasicBlock::Create(context, "next" + std::to_string(i), printBanglaFunc);
            funcBuilder.CreateBr(nextIdxBB);
            funcBuilder.SetInsertPoint(nextIdxBB);
            auto* idx3 = funcBuilder.CreateLoad(llvm::Type::getInt32Ty(context), idxPtr);
            auto* decIdx = funcBuilder.CreateSub(idx3, 
                llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1));
            funcBuilder.CreateStore(decIdx, idxPtr);
            funcBuilder.CreateBr(printLoopBB);
        }

        // Exit
        funcBuilder.SetInsertPoint(exitBB);
        auto* newlineStr = funcBuilder.CreateGlobalStringPtr("\n");
        funcBuilder.CreateCall(printfFunc, {newlineStr});
        funcBuilder.CreateRetVoid();
    }

public:
    CodeGenerator() : builder(context), module(std::make_unique<llvm::Module>("BanglaModule", context)) {
        // Create the print_bangla helper function first
        createPrintBanglaFunction();
        
        // Create main function
        auto mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), false);
        currentFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", module.get());
        auto block = llvm::BasicBlock::Create(context, "entry", currentFunc);
        builder.SetInsertPoint(block);
    }

    llvm::Value* generate(ASTNode* node) {
        if (!node) return nullptr;
        
        if (auto* intNode = dynamic_cast<IntNode*>(node)) {
            return llvm::ConstantInt::get(context, llvm::APInt(32, intNode->value));
        } else if (auto* floatNode = dynamic_cast<FloatNode*>(node)) {
            return llvm::ConstantFP::get(context, llvm::APFloat(floatNode->value));
        } else if (auto* stringNode = dynamic_cast<StringNode*>(node)) {
            return builder.CreateGlobalStringPtr(stringNode->value);
        } else if (auto* boolNode = dynamic_cast<BoolNode*>(node)) {
            return llvm::ConstantInt::get(context, llvm::APInt(1, boolNode->value));
        } else if (auto* varNode = dynamic_cast<VarNode*>(node)) {
            auto it = variables.find(varNode->name);
            if (it == variables.end()) {
                return nullptr;  // Should have been caught by semantic analysis
            }
            return builder.CreateLoad(llvm::Type::getInt32Ty(context), it->second);
        } else if (auto* assign = dynamic_cast<AssignNode*>(node)) {
            llvm::Value* val = generate(assign->value);
            llvm::Type* type = assign->type == "int" ? llvm::Type::getInt32Ty(context) : 
                              assign->type == "float" ? llvm::Type::getFloatTy(context) : 
                              llvm::Type::getInt8Ty(context)->getPointerTo();
            auto var = builder.CreateAlloca(type, nullptr, assign->var);
            builder.CreateStore(val, var);
            variables[assign->var] = var;
            return val;
        } else if (auto* reassign = dynamic_cast<ReassignNode*>(node)) {
            llvm::Value* val = generate(reassign->value);
            auto it = variables.find(reassign->var);
            if (it != variables.end()) {
                builder.CreateStore(val, it->second);
            }
            return val;
        } else if (auto* array = dynamic_cast<ArrayAssignNode*>(node)) {
            auto vals = dynamic_cast<ExprListNode*>(array->values);
            llvm::Type* intTy = llvm::Type::getInt32Ty(context);
            auto arrayTy = llvm::ArrayType::get(intTy, vals->expressions.size());
            auto alloc = builder.CreateAlloca(arrayTy, nullptr, array->var);
            for (size_t i = 0; i < vals->expressions.size(); i++) {
                auto val = generate(vals->expressions[i]);
                auto ptr = builder.CreateGEP(arrayTy, alloc, 
                    {llvm::ConstantInt::get(intTy, 0), llvm::ConstantInt::get(intTy, i)});
                builder.CreateStore(val, ptr);
            }
            variables[array->var] = alloc;
            return alloc;
        } else if (auto* print = dynamic_cast<PrintNode*>(node)) {
            llvm::Value* val = generate(print->expr);
            
            if (auto* strNode = dynamic_cast<StringNode*>(print->expr)) {
                // String: use printf directly
                auto printfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), 
                    {llvm::Type::getInt8Ty(context)->getPointerTo()}, true);
                auto printfFunc = module->getOrInsertFunction("printf", printfType);
                auto fmtStr = builder.CreateGlobalStringPtr("%s\n");
                builder.CreateCall(printfFunc, {fmtStr, val});
            } else {
                // Integer: use print_bangla function for Bangla output
                llvm::Value* intVal = val;
                // Ensure i32
                if (intVal->getType()->isIntegerTy(1)) {
                    intVal = builder.CreateZExt(intVal, llvm::Type::getInt32Ty(context));
                }
                builder.CreateCall(printBanglaFunc, {intVal});
            }
            return val;
        } else if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
            auto left = generate(binOp->left);
            auto right = generate(binOp->right);
            
            // Extend booleans to i32 for arithmetic
            if (left->getType()->isIntegerTy(1)) {
                left = builder.CreateZExt(left, llvm::Type::getInt32Ty(context));
            }
            if (right->getType()->isIntegerTy(1)) {
                right = builder.CreateZExt(right, llvm::Type::getInt32Ty(context));
            }
            
            if (binOp->op == "+") return builder.CreateAdd(left, right);
            if (binOp->op == "-") return builder.CreateSub(left, right);
            if (binOp->op == "*") return builder.CreateMul(left, right);
            if (binOp->op == "/") return builder.CreateSDiv(left, right);
            if (binOp->op == ">") return builder.CreateICmpSGT(left, right);
            if (binOp->op == "<") return builder.CreateICmpSLT(left, right);
            if (binOp->op == ">=") return builder.CreateICmpSGE(left, right);
            if (binOp->op == "<=") return builder.CreateICmpSLE(left, right);
            if (binOp->op == "==") return builder.CreateICmpEQ(left, right);
            if (binOp->op == "!=") return builder.CreateICmpNE(left, right);
            if (binOp->op == "&&") {
                auto leftBool = builder.CreateICmpNE(left, 
                    llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
                auto rightBool = builder.CreateICmpNE(right, 
                    llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
                return builder.CreateAnd(leftBool, rightBool);
            }
            if (binOp->op == "||") {
                auto leftBool = builder.CreateICmpNE(left, 
                    llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
                auto rightBool = builder.CreateICmpNE(right, 
                    llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));
                return builder.CreateOr(leftBool, rightBool);
            }
            return nullptr;
        } else if (auto* unaryOp = dynamic_cast<UnaryOpNode*>(node)) {
            auto operand = generate(unaryOp->operand);
            if (unaryOp->op == "!") {
                if (operand->getType()->isIntegerTy(1)) {
                    return builder.CreateNot(operand);
                } else {
                    auto isZero = builder.CreateICmpEQ(operand, 
                        llvm::ConstantInt::get(operand->getType(), 0));
                    return isZero;
                }
            }
            return nullptr;
        } else if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
            auto cond = generate(ifNode->condition);
            // Ensure condition is i1
            if (!cond->getType()->isIntegerTy(1)) {
                cond = builder.CreateICmpNE(cond, 
                    llvm::ConstantInt::get(cond->getType(), 0));
            }
            
            auto thenBB = llvm::BasicBlock::Create(context, "then", currentFunc);
            auto elseBB = ifNode->elseBranch ? llvm::BasicBlock::Create(context, "else", currentFunc) : nullptr;
            auto mergeBB = llvm::BasicBlock::Create(context, "merge", currentFunc);

            builder.CreateCondBr(cond, thenBB, elseBB ? elseBB : mergeBB);
            
            builder.SetInsertPoint(thenBB);
            generate(ifNode->thenBranch);
            if (!builder.GetInsertBlock()->getTerminator()) {
                builder.CreateBr(mergeBB);
            }

            if (elseBB) {
                builder.SetInsertPoint(elseBB);
                generate(ifNode->elseBranch);
                if (!builder.GetInsertBlock()->getTerminator()) {
                    builder.CreateBr(mergeBB);
                }
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
            // Ensure condition is i1
            if (!cond->getType()->isIntegerTy(1)) {
                cond = builder.CreateICmpNE(cond, 
                    llvm::ConstantInt::get(cond->getType(), 0));
            }
            builder.CreateCondBr(cond, bodyBB, exitBB);

            builder.SetInsertPoint(bodyBB);
            generate(whileNode->body);
            if (!builder.GetInsertBlock()->getTerminator()) {
                builder.CreateBr(loopBB);
            }

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
            auto prevInsertPoint = builder.GetInsertBlock();
            
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
            
            // Ensure function has a terminator
            if (!builder.GetInsertBlock()->getTerminator()) {
                builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));
            }
            
            currentFunc = prevFunc;
            builder.SetInsertPoint(prevInsertPoint);
            return funcDecl;
        } else if (auto* ret = dynamic_cast<ReturnNode*>(node)) {
            auto val = generate(ret->value);
            builder.CreateRet(val);
            return val;
        } else if (auto* call = dynamic_cast<CallNode*>(node)) {
            auto func = functions[call->name];
            std::vector<llvm::Value*> args;
            if (auto* argList = dynamic_cast<ExprListNode*>(call->args)) {
                for (auto* expr : argList->expressions) {
                    args.push_back(generate(expr));
                }
            }
            return builder.CreateCall(func, args);
        } else if (auto* block = dynamic_cast<BlockNode*>(node)) {
            for (auto* stmt : block->statements) generate(stmt);
            return nullptr;
        }
        return nullptr;
    }

    void finalize() { 
        if (!builder.GetInsertBlock()->getTerminator()) {
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