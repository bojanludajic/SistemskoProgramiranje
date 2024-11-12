#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int n;

int poSumi(const void *a, const void *b) {
    float suma1 = 0.0;
    float suma2 = 0.0;
    float* niza = *(float**)a;
    float* nizb = *(float**)b;
    for(int i = 0; i < n; i++) {
        suma1 += niza[i];
        suma2 += nizb[i];
    }
    
    return (suma1 > suma2) - (suma2 > suma1);
}

int poProseku(const void *a, const void *b) {
    float prosek1 = 0.0;
    float prosek2 = 0.0;
    float* niza = *(float**)a;
    float* nizb = *(float**)b;
    for(int i = 0; i < n; i++) {
        prosek1 += niza[i];
        prosek2 += nizb[i];
    }
    return (prosek1 > prosek2) - (prosek2 > prosek1);
}

int poGeoSredini(const void *a, const void *b) {
    float zbir1 = 1.0;
    float zbir2 = 1.0;
    float* niza = *(float**)a;
    float* nizb = *(float**)b;
    for(int i = 0; i < n; i++) {
        zbir1 *= niza[i];
        zbir2 *= nizb[i];
    }
    for(int i = 0; i < n; i++) {
        zbir1 = sqrt(zbir1);
        zbir2 = sqrt(zbir2);
    }
    return (zbir1 > zbir2) - (zbir2 > zbir1);
}

void sortiraj() {

}

int main() {
    scanf("%d", &n);
    float** matrica = malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++) {
        matrica[i] = malloc(n * sizeof(float));
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &matrica[i][j]);
        }
    }
    printf("Vrste sortirane po zbiru: \n ");
    qsort(matrica, n, sizeof(float*), poSumi);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%f ", matrica[i][j]);
        }
        printf("\n");
    }
    printf("Vrste sortirane po proseku: \n ");
    qsort(matrica, n, sizeof(float*), poProseku);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%f ", matrica[i][j]);
        }
        printf("\n");
    }
    printf("Vrste sortirane po geometrijskoj sredini: \n ");
    qsort(matrica, n, sizeof(float*), poGeoSredini);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%f ", matrica[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        free(matrica[i]);
    }
    free(matrica);
    return 0;
}