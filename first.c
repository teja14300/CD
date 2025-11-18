#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10] = {
    "E=E+T", "E=T",
    "T=T*F", "T=F",
    "F=(E)", "F=id"
};
int n = 6;
char first[10];

void add(char c) {
    if (!strchr(first, c)) {
        int len = strlen(first);
        first[len] = c;
        first[len+1] = '\0';
    }
}

void FIRST(char NT) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == NT) {
            char rhs = prod[i][2];

            if (islower(rhs) || rhs == '+' || rhs == '*' || rhs == '(')
                add(rhs);               // terminal

            else if (rhs == 'i')        // id → treat as 'i'
                add('i');

            else                        // another non-terminal
                FIRST(rhs);
        }
    }
}

int main() {
    char nt;
    printf("Enter Non-Terminal (E/T/F): ");
    scanf(" %c", &nt);

    first[0] = '\0';
    FIRST(nt);

    printf("FIRST(%c) = { ", nt);
    for (int i = 0; first[i]; i++)
        printf("%c ", first[i]);
    printf("}\n");

    return 0;
}
