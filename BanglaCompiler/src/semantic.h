#ifndef SEMANTIC_H
#define SEMANTIC_H
#include <map>
#include <string>
#include "ast.h"

class SymbolTable {
    std::map<std::string, std::string> table;
public:
    void insert(const std::string& var, const std::string& type) { table[var] = type; }
    std::string lookup(const std::string& var) { return table[var]; }
    bool exists(const std::string& var) { return table.find(var) != table.end(); }
};

class SemanticAnalyzer {
    SymbolTable symbols;
public:
    void analyze(ASTNode* node) {
        if (auto* assign = dynamic_cast<AssignNode*>(node)) {
            if (symbols.exists(assign->var)) throw std::runtime_error("Variable redefinition: " + assign->var);
            symbols.insert(assign->var, assign->type);
            analyze(assign->value);
        } else if (auto* var = dynamic_cast<VarNode*>(node)) {
            if (!symbols.exists(var->name)) throw std::runtime_error("Undefined variable: " + var->name);
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
        }
    }
};
#endif