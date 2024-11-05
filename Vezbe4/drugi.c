#include <stdio.h>
#include <stdlib.h>

void ucitaj(int* niz, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", (niz + i));
    }
}

void ispisi_obrnuto(int* niz, int n) {
    for(int i = n - 1; i >= 0; i--) {
        printf("%d\n", *(niz + i));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* niz = malloc(n * sizeof(int));
    ucitaj(niz, n);
    ispisi_obrnuto(niz, n);
    return 0;
}