#include <stdio.h>
#include <stdlib.h>

#define pi 3.14
int veci = 0;

float* izdvoj(float *niz, int n) {
    for(int i = 0; i < n; i++) {
        if(niz[i] > pi) {
            veci++;
        }
    }
    float *res = malloc(veci * sizeof(float));
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(niz[i] > pi) {
            res[j++] = niz[i];
        }
    }

    return res;
}

int main () {
    int n;
    scanf("%d", &n);
    float *niz = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        scanf("%f", (niz + i));
    }
    float *izdvojeni = izdvoj(niz, n);
    for(int i = 0; i < veci; i++) {
        printf("%f\n", izdvojeni[i]);
    }
}