#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *niz, int n) {
    for(int i = 0; i < n; i++) {
        int j = i - 1;
        int temp = niz[i];
        while(j >= 0 && niz[j] > temp) {
            niz[j + 1] = niz[j];
            j--;
        }
        niz[j + 1] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *niz = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", (niz + i));
    }
    insertionSort(niz, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }

    return 0;
}