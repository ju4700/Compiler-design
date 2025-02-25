#include "ast.h"
#include "semantic.h"
#include "codegen.h"
#include <iostream>
extern "C" int yyparse();
extern "C" int yylex();
extern FILE* yyin;
extern ASTNode* root;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input.bgl>\n";
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Cannot open file: " << argv[1] << "\n";
        return 1;
    }

    yyparse();
    if (!root) {
        std::cerr << "Parsing failed\n";
        return 1;
    }

    SemanticAnalyzer analyzer;
    try {
        analyzer.analyze(root);
    } catch (const std::exception& e) {
        std::cerr << "Semantic error: " << e.what() << "\n";
        return 1;
    }
    std::cout << "Semantic analysis passed\n";

    CodeGenerator gen;
    gen.generate(root);
    gen.finalize();
    gen.save("output.ll");

    system("clang output.ll -o program");  // Compile LLVM IR to executable
    std::cout << "Compilation complete. Run ./program\n";
    return 0;
}