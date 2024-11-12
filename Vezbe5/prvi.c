#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* niz = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", niz + i);
    }
    int* matrica = malloc(n * sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrica[(n * i) + j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrica[(n * i) + j] = niz[j] * niz[i];
            printf("%d ", matrica[(n * i) + j]);
        }
        printf("\n");
    }

    return 0;
}