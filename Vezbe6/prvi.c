#include <stdio.h>
#include <stdlib.h>

int izdvojeni = 0;

void ucitaj_cene(float **matrica, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &matrica[i][j]);
        }
    }
}

int veci_od(float b1, float b2) {
    return (b1 > b2) ? 1 : 0;
}

int manji_od(float b1, float b2) {
    return (b1 < b2) ? 1 : 0;
}

float** izdvoj(float **matrica, float cmp, int n, int(*fun)(float, float)) {
    float** res;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(fun(matrica[i][j], cmp)) {
                izdvojeni++;
            }
        }
    }

    res = malloc(izdvojeni * sizeof(float*));

    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(fun(matrica[i][j], cmp)) {
                res[k++] = &matrica[i][j];
            }
        }
    }

    return res;
}

void uvecaj(float *p, float posto) {
    *p += (*p * posto/100);
}

void umanji(float *p, float posto) {
    *p -= (*p * posto/100);
}

void modifikuj_vrednosti(float** niz, int izdvojeni, float posto, void(*fun)(float*, float)) {
    for(int i = 0; i < izdvojeni; i++) {
        fun(niz[i], posto);
    }
}

int main() {
    int n;
    printf("Unesite dimenzije matrice: ");
    scanf("%d", &n);
    float **matrica = malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(n * sizeof(float));
    }
    ucitaj_cene(matrica, n);

    printf("Uvecaj/umanji (1/0)");
    int izb;
    float procenat;
    float** res;
    scanf("%d", &izb);
    if(izb == 1) {
        printf("Koja je minimalna cena:");
        float min;
        scanf("%f", &min);
        printf("Za koliko %% ih uvecati:");
        scanf("%f", &procenat);
        res = izdvoj(matrica, min, n, manji_od);
        modifikuj_vrednosti(res, izdvojeni, procenat, uvecaj);

    } else {
        printf("Koja je maksimalna cena:");
        float max;
        scanf("%f", &max);
        printf("Za koliko %% ih umanjiti:");
        scanf("%f", &procenat);
        res = izdvoj(matrica, max, n, veci_od);
        modifikuj_vrednosti(res, izdvojeni, procenat, umanji);
    }

    for(int i = 0; i < izdvojeni; i++) {
        printf("%f\n", *(res[i]));
    }
    free(res);
    free(matrica);
    return 0;
}