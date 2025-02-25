%{
#include "parser.tab.h"
#include <string.h>
#define YY_DECL extern "C" int yylex()

// Convert Bangla digit string to integer
int bangla_to_int(const char* str) {
    int result = 0;
    const char* bangla_digits = "০১২৩৪৫৬৭৮৯";  // UTF-8 encoded Bangla digits 0-9
    for (int i = 0; str[i]; ) {
        int digit = -1;
        for (int j = 0; j < 10; j++) {
            if (strncmp(str + i, bangla_digits + j * 3, 3) == 0) {  // Each Bangla digit is 3 bytes in UTF-8
                digit = j;
                i += 3;  // Skip 3 bytes for the next character
                break;
            }
        }
        if (digit == -1) return 0;  // Invalid digit
        result = result * 10 + digit;
    }
    return result;
}
%}

%option noyywrap
%option 8bit
%option yylineno

DIGIT   [০-৯]
LETTER  [অ-ঔক-য়]

%%

"সংখ্যা"       { printf("NUMBER\n"); return NUMBER; }
"দশমিক"       { printf("FLOAT\n"); return FLOAT; }
"স্ট্রিং"      { printf("STRING\n"); return STRING; }
"বুলিয়ান"     { printf("BOOL\n"); return BOOL; }
"যদি"         { printf("IF\n"); return IF; }
"নাহলে"       { printf("ELSE\n"); return ELSE; }
"যতক্ষণ"      { printf("WHILE\n"); return WHILE; }
"ফাংশন"      { printf("FUNCTION\n"); return FUNCTION; }
"ফিরিয়ে দাও"  { printf("RETURN\n"); return RETURN; }
"দেখাও"       { printf("PRINT\n"); return PRINT; }
"সত্য"        { yylval.bval = true; printf("TRUE\n"); return TRUE; }
"মিথ্যা"      { yylval.bval = false; printf("FALSE\n"); return FALSE; }
{DIGIT}+      { yylval.ival = bangla_to_int(yytext); printf("INTEGER %d\n", yylval.ival); return INTEGER; }
{DIGIT}+"."{DIGIT}+ { yylval.fval = atof(yytext); printf("FLOATVAL %f\n", yylval.fval); return FLOATVAL; }  // Placeholder; needs UTF-8 fix if used
"\""[^\"]*"\"" { yylval.sval = strdup(yytext + 1); yylval.sval[strlen(yylval.sval) - 1] = 0; printf("STRINGVAL %s\n", yylval.sval); return STRINGVAL; }
"="           { printf("ASSIGN\n"); return ASSIGN; }
";"           { printf("SEMICOLON\n"); return SEMICOLON; }
"("           { printf("LPAREN\n"); return LPAREN; }
")"           { printf("RPAREN\n"); return RPAREN; }
"{"           { printf("LBRACE\n"); return LBRACE; }
"}"           { printf("RBRACE\n"); return RBRACE; }
"["           { printf("LBRACKET\n"); return LBRACKET; }
"]"           { printf("RBRACKET\n"); return RBRACKET; }
","           { printf("COMMA\n"); return COMMA; }
">"           { printf("GT\n"); return GT; }
"<"           { printf("LT\n"); return LT; }
"=="          { printf("EQ\n"); return EQ; }
"+"           { printf("PLUS\n"); return PLUS; }
"-"           { printf("MINUS\n"); return MINUS; }
"*"           { printf("MUL\n"); return MUL; }
"/"           { printf("DIV\n"); return DIV; }
"এবং"         { printf("AND\n"); return AND; }
"অথবা"        { printf("OR\n"); return OR; }
{LETTER}+     { yylval.sval = strdup(yytext); printf("IDENTIFIER %s\n", yylval.sval); return IDENTIFIER; }
[ \t\n]+      { /* Ignore whitespace */ }
.             { printf("Unknown character: %s\n", yytext); }

%%

/* No main() here */