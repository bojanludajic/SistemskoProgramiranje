#include <stdio.h>
#include <stdlib.h>

void ucitaj(float** matrica, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%f", *(matrica + i) + j);
        }
    }
}

float* maksimumi(float** matrica, int n, int m) {
    float* res = malloc(sizeof(float) * n);
    for(int i = 0; i < n; i++) {
        *(res + i) = 0.0;
    }
    for(int i = 0; i < n; i++) {
        float max = 0;
        for(int j = 0; j < m; j++) {
            if(*(*(matrica + i) + j) > max) {
                max = *(*(matrica + i) + j);
            }
        }
        *(res + i) = max;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    float** matrica = malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(sizeof(float) * m);
    }
    ucitaj(matrica, n, m);
    float* res = maksimumi(matrica, n, m);
    for(int i = 0; i < n; i++) {
        printf("%f\n", *(res + i));
    }
    return 0;
}