#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, n;

    printf("Enter size: ");
    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int));   // HEAP ALLOCATION

    if (!p) {
        printf("Memory not allocated\n");
        return 0;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("You entered:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    free(p);   // FREE HEAP MEMORY
    return 0;
}
