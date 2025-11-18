#include <stdio.h>
#include <string.h>

char str[50];
int i=0;

// Forward declarations
int E();
int Ep();
int T();
int Tp();
int F();

int E() {              // E → T E'
    if (T())
        return Ep();
    return 0;
}

int Ep() {             // E' → + T E' | ε
    if (str[i] == '+') {
        i++;
        if (T())
            return Ep();
        else
            return 0;
    }
    return 1;          // epsilon
}

int T() {              // T → F T'
    if (F())
        return Tp();
    return 0;
}

int Tp() {             // T' → * F T' | ε
    if (str[i] == '*') {
        i++;
        if (F())
            return Tp();
        else
            return 0;
    }
    return 1;          // epsilon
}

int F() {              // F → (E) | id
    if (str[i] == '(') {
        i++;
        if (E() && str[i] == ')') {
            i++;
            return 1;
        }
        return 0;
    }

    if (str[i] == 'i' && str[i+1] == 'd') {   // id
        i += 2;
        return 1;
    }

    return 0;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", str);

    if (E() && str[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
