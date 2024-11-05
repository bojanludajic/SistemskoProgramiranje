#include <stdio.h>
#include <stdlib.h>

void sortiraj(int* niz, int n, int** nizp) {
    for(int i = 0; i < n; i++) {
        nizp[i] = &niz[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int minInd = i;
        for(int j = i + 1; j < n; j++) {
            if(*nizp[j] < *nizp[minInd]) {
                minInd = j;
            }
        }
        int* temp = nizp[i];
        nizp[i] = nizp[minInd];
        nizp[minInd] = temp;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int* niz = malloc(n * sizeof(int));
    int** nizp = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        scanf("%d", niz + i);
    }
    sortiraj(niz, n, nizp);
    for(int i = 0; i < n; i++) {
        printf("%d\n", *nizp[i]);
    }
    return 0;
}