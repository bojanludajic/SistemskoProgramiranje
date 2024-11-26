#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ucitaj_matricu(float** matrica, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &matrica[i][j]);
        }
    }

}

float* izdvoj(float** matrica, int n) {
    float* res = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        res[i] = matrica[i][i];
    }
    return res;
}

float aritmeticka_sredina(float n, float m) {
    return (n + m) / 2;
}

float geometrijska_sredina(float n, float m) {
    return sqrtf(n * m);
}

float* novi_niz(float* niz, int duzina_niza, float (*fun)(float, float)) {
    float* res = malloc((duzina_niza - 1) * sizeof(float));
    for(int i = 0; i < duzina_niza; i++) {
        res[i] = fun(niz[i], niz[i + 1]);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    float** matrica = malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(n * sizeof(float));
    }

    ucitaj_matricu(matrica, n);
    float* dijagonala = izdvoj(matrica, n);
    
    float* resAr = novi_niz(dijagonala, n - 1, aritmeticka_sredina);
    float* resGeom = novi_niz(dijagonala, n - 1, geometrijska_sredina);

    for(int i = 0; i < n - 1; i++) {
        printf("%f\n", resGeom[i]);
    }

    return 0;
}