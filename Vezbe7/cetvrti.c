#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ucitaj(char** knjige, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", knjige[i]);
        getchar();
    }
}

void sortiraj(char** knjige, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(knjige[i], knjige[j]) > 0) {
                char *temp = knjige[i];
                knjige[i] = knjige[j];
                knjige[j] = temp;
            }
        }
    } 
}


int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char **knjige = malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        knjige[i] = malloc(50 * sizeof(char));
    }
    ucitaj(knjige, n);
    sortiraj(knjige, n);
    for(int i = 0; i < n; i++) {
        printf("%s\n", knjige[i]);
    }
    return 0;
}