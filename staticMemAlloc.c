#include <stdio.h>

// Static (global) variable
static int counter = 0;

void increment() {
    static int local_static = 0; // static inside function
    local_static++;
    counter++;
    printf("local_static = %d, counter = %d\n", local_static, counter);
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
