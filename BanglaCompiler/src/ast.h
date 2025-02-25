#ifndef AST_H
#define AST_H
#include <string>
#include <vector>

class ASTNode { public: virtual ~ASTNode() = default; };
class IntNode : public ASTNode { public: int value; IntNode(int v) : value(v) {} };
class FloatNode : public ASTNode { public: float value; FloatNode(float v) : value(v) {} };
class StringNode : public ASTNode { public: std::string value; StringNode(const std::string& v) : value(v) {} };
class BoolNode : public ASTNode { public: bool value; BoolNode(bool v) : value(v) {} };
class VarNode : public ASTNode { public: std::string name; VarNode(const std::string& n) : name(n) {} };
class AssignNode : public ASTNode { 
public: 
    std::string var, type; 
    ASTNode* value; 
    AssignNode(const std::string& v, const std::string& t, ASTNode* val) : var(v), type(t), value(val) {} 
};
class PrintNode : public ASTNode { public: ASTNode* expr; PrintNode(ASTNode* e) : expr(e) {} };
class IfNode : public ASTNode { 
public: 
    ASTNode* condition, *thenBranch, *elseBranch; 
    IfNode(ASTNode* c, ASTNode* t, ASTNode* e) : condition(c), thenBranch(t), elseBranch(e) {}
};
class WhileNode : public ASTNode { 
public: 
    ASTNode* condition, *body; 
    WhileNode(ASTNode* c, ASTNode* b) : condition(c), body(b) {}
};
class BinaryOpNode : public ASTNode { 
public: 
    ASTNode* left, *right; 
    std::string op; 
    BinaryOpNode(ASTNode* l, const std::string& o, ASTNode* r) : left(l), op(o), right(r) {}
};
class BlockNode : public ASTNode { 
public: 
    std::vector<ASTNode*> statements; 
    BlockNode(ASTNode* stmt, ASTNode* next = nullptr) {
        statements.push_back(stmt);
        if (auto block = dynamic_cast<BlockNode*>(next)) {
            statements.insert(statements.end(), block->statements.begin(), block->statements.end());
        } else if (next) statements.push_back(next);
    }
};

extern ASTNode* root;
#endif