%code requires {
    #include "ast.h"
}

%{
#include <iostream>
#include <stdbool.h>
#include "ast.h"
extern "C" int yylex();
extern "C" int yyparse();
extern int yylineno;
void yyerror(const char* s) { std::cerr << "Parse Error: " << s << " at line " << yylineno << std::endl; }
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

%type <node> program stmt expr array expr_list func_def param_list call_args optional_else

%left OR
%left AND
%left EQ
%left GT LT
%left PLUS MINUS
%left MUL DIV

%%

program: stmt { root = $1; }
       ;

stmt: NUMBER IDENTIFIER ASSIGN expr SEMICOLON { $$ = new AssignNode($2, "int", $4); }
    | FLOAT IDENTIFIER ASSIGN expr SEMICOLON { $$ = new AssignNode($2, "float", $4); }
    | STRING IDENTIFIER ASSIGN expr SEMICOLON { $$ = new AssignNode($2, "string", $4); }
    | BOOL IDENTIFIER ASSIGN expr SEMICOLON { $$ = new AssignNode($2, "bool", $4); }
    | NUMBER LBRACKET RBRACKET IDENTIFIER ASSIGN array SEMICOLON { $$ = new ArrayAssignNode($4, $6); }
    | PRINT LPAREN expr RPAREN SEMICOLON { $$ = new PrintNode($3); }
    | IF LPAREN expr RPAREN LBRACE stmt RBRACE optional_else { $$ = new IfNode($3, $6, $8); }
    | WHILE LPAREN expr RPAREN LBRACE stmt RBRACE { $$ = new WhileNode($3, $6); }
    | func_def { $$ = $1; }
    | RETURN expr SEMICOLON { $$ = new ReturnNode($2); }
    ;

optional_else: /* empty */ { $$ = nullptr; }
             | ELSE LBRACE stmt RBRACE { $$ = $3; }
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

func_def: FUNCTION IDENTIFIER LPAREN param_list RPAREN LBRACE stmt RBRACE { $$ = new FunctionNode($2, $4, $7); }
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