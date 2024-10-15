#include <stdio.h>

int main() {
    int n;
    int m;
    printf("Duzina prvog niza: ");
    scanf("%d", &n);
    printf("Duzina druggog niza: ");
    scanf("%d", &m);
    float prvi[n];
    float drugi[m];
    int prviZbir = 0;
    int drugiZbir = 0;
    for(int i = 0; i < n; i++) {
        scanf("%f", &prvi[i]);
        prviZbir += prvi[i];
    }
    for(int i = 0; i < m; i++) {
        scanf("%f", &drugi[i]);
        drugiZbir += drugi[i];
    }
    float res[m + n];
    if(prviZbir > drugiZbir) {
        for(int i = 0; i < n; i++) {
            res[i] = prvi[i];
        }
        for(int i = 0; i < m; i++) {
            res[i + n] = drugi[i];
        }
    } else {
        for(int i = 0; i < m; i++) {
            res[i] = drugi[i];
        }
        for(int i = 0; i < n; i++) {
            res[i + m] = prvi[i];
        }
    }
    for(int i = 0; i < m + n; i++) {
        printf("%f ", res[i]);
    };
    return 0;
}