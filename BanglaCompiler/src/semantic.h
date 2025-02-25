#ifndef SEMANTIC_H
#define SEMANTIC_H
#include <map>
#include <string>
#include <stdexcept>  // Added for std::runtime_error
#include "ast.h"

class SymbolTable {
    std::map<std::string, std::string> variables;  // var -> type
    std::map<std::string, std::vector<std::string>> functions;  // func -> param types
public:
    void insertVar(const std::string& var, const std::string& type) { 
        if (variables.count(var)) throw std::runtime_error("Variable redefinition: " + var);
        variables[var] = type; 
    }
    std::string lookupVar(const std::string& var) { 
        if (!variables.count(var)) throw std::runtime_error("Undefined variable: " + var);
        return variables[var]; 
    }
    void insertFunc(const std::string& func, const std::vector<std::string>& paramTypes) { 
        if (functions.count(func)) throw std::runtime_error("Function redefinition: " + func);
        functions[func] = paramTypes; 
    }
    std::vector<std::string> lookupFunc(const std::string& func) { 
        if (!functions.count(func)) throw std::runtime_error("Undefined function: " + func);
        return functions[func]; 
    }
};

class SemanticAnalyzer {
    SymbolTable symbols;
public:
    void analyze(ASTNode* node) {
        if (auto* assign = dynamic_cast<AssignNode*>(node)) {
            symbols.insertVar(assign->var, assign->type);
            analyze(assign->value);
        } else if (auto* array = dynamic_cast<ArrayAssignNode*>(node)) {
            symbols.insertVar(array->var, "array<int>");
            analyze(array->values);
        } else if (auto* var = dynamic_cast<VarNode*>(node)) {
            symbols.lookupVar(var->name);
        } else if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
            analyze(binOp->left);
            analyze(binOp->right);
        } else if (auto* block = dynamic_cast<BlockNode*>(node)) {
            for (auto* stmt : block->statements) analyze(stmt);
        } else if (auto* print = dynamic_cast<PrintNode*>(node)) {
            analyze(print->expr);
        } else if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
            analyze(ifNode->condition);
            analyze(ifNode->thenBranch);
            if (ifNode->elseBranch) analyze(ifNode->elseBranch);
        } else if (auto* whileNode = dynamic_cast<WhileNode*>(node)) {
            analyze(whileNode->condition);
            analyze(whileNode->body);
        } else if (auto* func = dynamic_cast<FunctionNode*>(node)) {
            std::vector<std::string> paramTypes;
            for (auto p = dynamic_cast<ParamNode*>(func->params); p; p = dynamic_cast<ParamNode*>(p->next)) {
                paramTypes.push_back(p->type);
                symbols.insertVar(p->name, p->type);
            }
            symbols.insertFunc(func->name, paramTypes);
            analyze(func->body);
        } else if (auto* ret = dynamic_cast<ReturnNode*>(node)) {
            analyze(ret->value);
        } else if (auto* call = dynamic_cast<CallNode*>(node)) {
            auto expectedParams = symbols.lookupFunc(call->name);
            std::vector<ASTNode*> args;
            for (auto a = dynamic_cast<ExprListNode*>(call->args); a; a = dynamic_cast<ExprListNode*>(a->expressions.size() > 1 ? a->expressions[1] : nullptr)) {
                args.push_back(a->expressions[0]);
                analyze(a->expressions[0]);
            }
            if (args.size() != expectedParams.size()) throw std::runtime_error("Argument count mismatch for " + call->name);
        } else if (auto* list = dynamic_cast<ExprListNode*>(node)) {
            for (auto* expr : list->expressions) analyze(expr);
        }
    }
};
#endif