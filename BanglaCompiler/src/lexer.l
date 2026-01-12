%{
#include "parser.tab.h"
#include <string.h>
#define YY_DECL extern "C" int yylex()

// Convert Bangla digit string to integer
int bangla_to_int(const char* str) {
    int result = 0;
    int negative = 0;
    const char* bangla_digits = "০১২৩৪৫৬৭৮৯";  // UTF-8 encoded Bangla digits 0-9
    int i = 0;
    
    // Check for negative sign
    if (str[0] == '-') {
        negative = 1;
        i = 1;
    }
    
    for (; str[i]; ) {
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
    return negative ? -result : result;
}

// Convert Bangla digit string to float
double bangla_to_float(const char* str) {
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 1.0;
    int in_fraction = 0;
    const char* bangla_digits = "০১২৩৪৫৬৭৮৯";  // UTF-8 encoded Bangla digits 0-9
    
    for (int i = 0; str[i]; ) {
        if (str[i] == '.') {
            in_fraction = 1;
            i++;
            continue;
        }
        
        int digit = -1;
        for (int j = 0; j < 10; j++) {
            if (strncmp(str + i, bangla_digits + j * 3, 3) == 0) {
                digit = j;
                i += 3;
                break;
            }
        }
        if (digit == -1) break;
        
        if (in_fraction) {
            divisor *= 10.0;
            fraction += digit / divisor;
        } else {
            result = result * 10.0 + digit;
        }
    }
    return result + fraction;
}
%}

%option noyywrap
%option 8bit
%option yylineno

DIGIT   [০-৯]
LETTER  [অ-ঔক-য়]

%%

"সংখ্যা"       { return NUMBER; }
"দশমিক"       { return FLOAT; }
"স্ট্রিং"      { return STRING; }
"বুলিয়ান"     { return BOOL; }
"যদি"         { return IF; }
"নাহলে"       { return ELSE; }
"যতক্ষণ"      { return WHILE; }
"ফাংশন"      { return FUNCTION; }
"ফিরিয়ে দাও"  { return RETURN; }
"দেখাও"       { return PRINT; }
"সত্য"        { yylval.bval = true; return TRUE; }
"মিথ্যা"      { yylval.bval = false; return FALSE; }
{DIGIT}+      { yylval.ival = bangla_to_int(yytext); return INTEGER; }
{DIGIT}+"."{DIGIT}+ { yylval.fval = bangla_to_float(yytext); return FLOATVAL; }
"\""[^\"]*"\"" { yylval.sval = strdup(yytext + 1); yylval.sval[strlen(yylval.sval) - 1] = 0; return STRINGVAL; }
"="           { return ASSIGN; }
";"           { return SEMICOLON; }
"("           { return LPAREN; }
")"           { return RPAREN; }
"{"           { return LBRACE; }
"}"           { return RBRACE; }
"["           { return LBRACKET; }
"]"           { return RBRACKET; }
","           { return COMMA; }
">="          { return GE; }
"<="          { return LE; }
"!="          { return NE; }
">"           { return GT; }
"<"           { return LT; }
"=="          { return EQ; }
"+"           { return PLUS; }
"-"           { return MINUS; }
"*"           { return MUL; }
"/"           { return DIV; }
"এবং"         { return AND; }
"অথবা"        { return OR; }
"না"          { return NOT; }
{LETTER}+     { yylval.sval = strdup(yytext); return IDENTIFIER; }
[ \t\n\r]+    { /* Ignore whitespace */ }
.             { /* Ignore unknown characters silently */ }

%%

/* No main() here */