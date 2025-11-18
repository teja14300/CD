%{
int words = 0, lines = 0;
%}

%%

[ \t]+        ;           // ignore spaces & tabs
\n            { lines++; }
[A-Za-z0-9]+  { words++; }

.             ;           // ignore other characters
%%

int main() {
    yylex();
    printf("Lines = %d\nWords = %d\n", lines, words);
    return 0;
}

int yywrap() { return 1; }
