#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int niz[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(niz[i] > niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    return 0;
}