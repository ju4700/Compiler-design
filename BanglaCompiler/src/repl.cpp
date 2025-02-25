#include <iostream>
#include "ast.h"
#include "semantic.h"
#include "codegen.h"
extern "C" int yyparse();

int main() {
    std::cout << "Bangla REPL\n";
    while (true) {
        std::cout << "> ";
        yyparse();
        if (!root) continue;
        SemanticAnalyzer analyzer;
        analyzer.analyze(root);
        CodeGenerator gen;
        gen.generate(root);
        gen.finalize();
        gen.save("repl.ll");
        system("clang -S -emit-llvm repl.ll -o repl.s && gcc repl.s -o repl && ./repl");
        root = nullptr;
    }
    return 0;
}