%{
#include <stdio.h>
%}

%%

[A-Z]+      { printf("CAPITAL STRING: %s\n", yytext); }
[a-zA-Z]+   { printf("NOT CAPITAL: %s\n", yytext); }
[ \t\n]+    ;        // ignore whitespace
.           { printf("OTHER: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() { return 1; }
