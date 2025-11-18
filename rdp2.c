#include <stdio.h>

char str[50];
int i = 0;

int S();   // forward declarations
int L();

int S() {
    if (str[i] == 'a') {   // S → a
        i++;
        return 1;
    }
    if (str[i] == '(') {   // S → ( L )
        i++;
        if (!L()) return 0;
        if (str[i] == ')') { i++; return 1; }
        return 0;
    }
    return 0;
}

int L() {                   // L → S L'
    if (!S()) return 0;
    while (str[i] == ',') { // L' → , S L'
        i++;
        if (!S()) return 0;
    }
    return 1;
}

int main() {
    printf("Enter string: ");
    scanf("%s", str);

    if (S() && str[i] == '\0')
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
