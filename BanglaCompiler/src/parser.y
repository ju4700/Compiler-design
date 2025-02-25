%code requires {
    #include "ast.h"
}

%{
#include <iostream>
#include <stdbool.h>
#include "ast.h"
extern "C" int yylex();   // Ensure C linkage
extern "C" int yyparse(); // Ensure C linkage for consistency
void yyerror(const char* s) { std::cerr << "Parse Error: " << s << std::endl; }
extern ASTNode* root;
%}

%union {
    int ival;
    float fval;
    bool bval;
    char* sval;
    ASTNode* node;
}

%token NUMBER FLOAT STRING BOOL IF ELSE WHILE FUNCTION RETURN PRINT
%token ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET COMMA GT LT EQ PLUS MINUS MUL DIV AND OR
%token <ival> INTEGER
%token <fval> FLOATVAL
%token <bval> TRUE FALSE
%token <sval> STRINGVAL IDENTIFIER

%type <node> program stmts stmt expr array expr_list func_def param_list call_args

%left OR
%left AND
%left EQ
%left GT LT
%left PLUS MINUS
%left MUL DIV

%%

program: stmts { root = $1; }
       ;

stmts: stmt SEMICOLON stmts { $$ = new BlockNode($1, $3); }
     | stmt SEMICOLON       { $$ = $1; }
     ;

stmt: NUMBER IDENTIFIER ASSIGN expr { $$ = new AssignNode($2, "int", $4); }
    | FLOAT IDENTIFIER ASSIGN expr  { $$ = new AssignNode($2, "float", $4); }
    | STRING IDENTIFIER ASSIGN expr { $$ = new AssignNode($2, "string", $4); }
    | BOOL IDENTIFIER ASSIGN expr   { $$ = new AssignNode($2, "bool", $4); }
    | NUMBER LBRACKET RBRACKET IDENTIFIER ASSIGN array { $$ = new ArrayAssignNode($4, $6); }
    | PRINT LPAREN expr RPAREN      { $$ = new PrintNode($3); }
    | IF LPAREN expr RPAREN LBRACE stmts RBRACE { $$ = new IfNode($3, $6, nullptr); }
    | IF LPAREN expr RPAREN LBRACE stmts RBRACE ELSE LBRACE stmts RBRACE { $$ = new IfNode($3, $6, $10); }
    | WHILE LPAREN expr RPAREN LBRACE stmts RBRACE { $$ = new WhileNode($3, $6); }
    | func_def { $$ = $1; }
    | RETURN expr { $$ = new ReturnNode($2); }
    ;

expr: INTEGER       { $$ = new IntNode($1); }
    | FLOATVAL      { $$ = new FloatNode($1); }
    | STRINGVAL     { $$ = new StringNode($1); }
    | TRUE          { $$ = new BoolNode($1); }
    | FALSE         { $$ = new BoolNode($1); }
    | IDENTIFIER    { $$ = new VarNode($1); }
    | IDENTIFIER LPAREN call_args RPAREN { $$ = new CallNode($1, $3); }
    | expr PLUS expr { $$ = new BinaryOpNode($1, "+", $3); }
    | expr MINUS expr { $$ = new BinaryOpNode($1, "-", $3); }
    | expr MUL expr  { $$ = new BinaryOpNode($1, "*", $3); }
    | expr DIV expr  { $$ = new BinaryOpNode($1, "/", $3); }
    | expr GT expr   { $$ = new BinaryOpNode($1, ">", $3); }
    | expr LT expr   { $$ = new BinaryOpNode($1, "<", $3); }
    | expr EQ expr   { $$ = new BinaryOpNode($1, "==", $3); }
    | expr AND expr  { $$ = new BinaryOpNode($1, "&&", $3); }
    | expr OR expr   { $$ = new BinaryOpNode($1, "||", $3); }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

array: LBRACKET expr_list RBRACKET { $$ = $2; }
     ;

expr_list: expr { $$ = new ExprListNode($1); }
         | expr COMMA expr_list { $$ = new ExprListNode($1, $3); }
         ;

func_def: FUNCTION IDENTIFIER LPAREN param_list RPAREN LBRACE stmts RBRACE { $$ = new FunctionNode($2, $4, $7); }
        ;

param_list: /* empty */ { $$ = nullptr; }
          | NUMBER IDENTIFIER { $$ = new ParamNode($2, "int"); }
          | NUMBER IDENTIFIER COMMA param_list { $$ = new ParamNode($2, "int", $4); }
          ;

call_args: /* empty */ { $$ = nullptr; }
         | expr { $$ = new ExprListNode($1); }
         | expr COMMA call_args { $$ = new ExprListNode($1, $3); }
         ;
%%

/* No main() here */