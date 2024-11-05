#include <stdio.h>

void stat(int* niz, int n, int* min, int* max, float* avg);

int main() {
    int n;
    scanf("%d", &n);
    int niz[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    int min, max;
    float avg;
    stat(niz, n, &min, &max, &avg);
    printf("%d %d %f", min, max, avg);
    return 0;
}

void stat(int* niz, int n, int* min, int* max, float* avg) {
    *max = 0;
    *min = __INT_MAX__;
    *avg = 0.0;
    for(int i = 0; i < n; i++) {
        if(*(niz + i) > *max) {
            *max = *(niz + i);
        }
        if(*(niz + i) < *min) {
            *min = *(niz + i);
        }
        *avg += *(niz + i);
    }
    *avg /= n;
}