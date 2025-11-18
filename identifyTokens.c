#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(const char *word) {
    const char *keywords[] = {
        "int", "char", "return", "if", "else", "while", "for", "float", "double", "void"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char c;
    while ((c = getchar()) != EOF) {

        // Identifier or Keyword
        if (isalpha(c)) {
            char buffer[128];
            int i = 0;

            buffer[i++] = c;
            while (isalnum(c = getchar())) buffer[i++] = c;
            buffer[i] = '\0';

            if (isKeyword(buffer))
                printf("KEYWORD: %s\n", buffer);
            else
                printf("IDENTIFIER: %s\n", buffer);

            // unread the last non-alnum char
            ungetc(c, stdin);
        }

        // Number
        else if (isdigit(c)) {
            printf("number: %c", c);
            while (isdigit(c = getchar())) printf("%c", c);
            printf("\n");
            ungetc(c, stdin);
        }

        // Comment
        else if (c == '/') {
            char d = getchar();
            if (d == '/') {
                printf("COMMENT: //");
                while ((c = getchar()) != '\n') printf("%c", c);
                printf("\n");
            } 
            else if (d == '*') {
                printf("COMMENT: /*");
                while (!(c == '*' && (d = getchar()) == '/')) c = getchar();
                printf("*/\n");
            } 
            else {
                printf("OPERATOR: /\n");
                ungetc(d, stdin);
            }
        }

        // Operators
        else if (c=='+'||c=='-'||c=='*'||c=='=') {
            printf("OPERATOR: %c\n", c);
        }
    }
    return 0;
}
