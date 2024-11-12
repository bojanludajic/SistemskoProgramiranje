#include <stdio.h>
#include <stdlib.h>

int duzina = 0;

void ucitaj(int** matrica, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
}

int* izdvoj(int** matrica, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrica[i][j] > 20.0) {
                duzina++;
            }
        }
    }
    int* niz = malloc(duzina * sizeof(int));
    int ind = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrica[i][j] > 20.0) {
                niz[ind] = matrica[i][j];
                ind++;
            }
        }
    }
    return niz;
}

int saberi(int a, int b) {
    return a + b;
}

int oduzmi(int a, int b) {
    return a - b;
}

float operacija(int* niz, int n, int(*func)(int, int)) {
    int res = 0.0;
    for(int i = 0; i < n; i++) {
        res = func(res, niz[i]);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int** matrica = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(n * sizeof(int));
    }
    ucitaj(matrica, n);
    int* niz = izdvoj(matrica, n);
    printf("sabiranje/oduzimanje (0/1)");
    int x;
    scanf("%d", &x);
    if(x == 0) {
        printf("%f ", operacija(niz, n, saberi));
    } else {
        printf("%f ", operacija(niz, n, oduzmi));
    }
    return 0;
}