#include <stdio.h>
#include <string.h>

int main() {
    char niz[5][100];
    for(int i = 0; i < 5; i++) {
        scanf("%s", niz[i]);
    }
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(strcmp(niz[i], niz[j]) > 0) {
                int duzina = strlen(niz[i]);
                char temp[duzina];
                strcpy(temp, niz[i]);
                strcpy(niz[i], niz[j]);
                strcpy(niz[j], temp);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%s ", niz[i]);
    }
    return 0;
}