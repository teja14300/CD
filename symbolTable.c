#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol {
    char name[20];
    char type[10];
} table[MAX];

int n = 0;

void insert(char *name, char *type) {
    strcpy(table[n].name, name);
    strcpy(table[n].type, type);
    n++;
}

int search(char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(table[i].name, name) == 0)
            return i;
    return -1;
}

void display() {
    printf("\nSymbol Table:\nName\tType\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%s\n", table[i].name, table[i].type);
}

int main() {
    insert("x", "int");
    insert("y", "float");
    display();

    int pos = search("x");
    if (pos != -1) printf("\nFound %s at %d\n", table[pos].name, pos);
}
