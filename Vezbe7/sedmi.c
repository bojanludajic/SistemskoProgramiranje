#include <stdio.h>
#include <stdlib.h>

void ucitaj_matricu(float** matrica, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%f", &matrica[i][j]);
        }
    }
}

float* izdovoj_vrstu(float** matrica, int n, int m, int i) {
    float* res = malloc(m * sizeof(float));
    for(int j = 0; j < m; i++) {
        res[j] = matrica[i][j];
    }
    return res;
}


int br_pozitivnih(float* niz, int duzina_niza) {
    int count = 0;
    for(int i = 0; i < duzina_niza; i++) {
        if(niz[i] > 0) {
            count++;
        }
    }
    return count;
}

int br_negativnih(float* niz, int duzina_niza) {
    int count = 0;
    for(int i = 0; i < duzina_niza; i++) {
        if(niz[i] < 0) {
            count++;
        }
    }
    return count;
}

int najvise_sa_znakom(float** matrica, int n, int m, int (*fun)(float*, int)) {
    int ind = 0;
    int max = fun(matrica[0], m);
    for(int i = 1; i < n; i++) {
        if(fun(matrica[i], m) > max) {
            ind = i;
            max = fun(matrica[i], m);
        }
    }
    return ind;
}


int main() {
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);

    float** matrica = malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(m * sizeof(float));
    }

    ucitaj_matricu(matrica, n, m);

    int pos = najvise_sa_znakom(matrica, n, m, br_pozitivnih);
    int neg = najvise_sa_znakom(matrica, n, m, br_negativnih);

    printf("Najvise pozitivnih brojeva ima u %d. vrsti\n", pos);
    printf("Najvise negativnih brojeva ima u %d. vrsti", neg);

    for(int i = 0; i < n; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}