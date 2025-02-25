%{
#include "parser.tab.h"  // Token definitions from Bison
#include <string>

#define YY_DECL extern "C" int yylex()  // Avoid C++ name mangling
%}

/* No file wrapping needed */
%option noyywrap  
/* Support UTF-8 Bangla characters */
%option 8bit      

DIGIT   [০-৯]
LETTER  [অ-ঔক-য়]

%%

"সংখ্যা"       { return NUMBER; }
"দশমিক"       { return FLOAT; }
"স্ট্রিং"      { return STRING; }
"বুলিয়ান"     { return BOOL; }
"যদি"         { return IF; }
"নাহলে"       { return ELSE; }
"যতক্ষণ"      { return WHILE; }
"জন্য"        { return FOR; }
"ফাংশন"      { return FUNCTION; }
"ফিরিয়ে দাও"  { return RETURN; }
"দেখাও"       { return PRINT; }
"ইনপুট"       { return INPUT; }
"সত্য"        { yylval.bval = true; return TRUE; }
"মিথ্যা"      { yylval.bval = false; return FALSE; }
{DIGIT}+      { yylval.ival = atoi(yytext); return INTEGER; }
{DIGIT}+"."{DIGIT}+ { yylval.fval = atof(yytext); return FLOATVAL; }
"\""[^\"]*"\"" { yylval.sval = strdup(yytext + 1); yylval.sval[strlen(yval.sval) - 1] = 0; return STRINGVAL; }
"="           { return ASSIGN; }
";"           { return SEMICOLON; }
"("           { return LPAREN; }
")"           { return RPAREN; }
"{"           { return LBRACE; }
"}"           { return RBRACE; }
">"           { return GT; }
"<"           { return LT; }
"=="          { return EQ; }
"+"           { return PLUS; }
"-"           { return MINUS; }
"*"           { return MUL; }
"/"           { return DIV; }
"এবং"         { return AND; }
"অথবা"        { return OR; }
{LETTER}+     { yylval.sval = strdup(yytext); return IDENTIFIER; }
[ \t\n]+      { /* Ignore whitespace */ }
.             { printf("Unknown character: %s\n", yytext); }

%%