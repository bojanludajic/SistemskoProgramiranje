#include <stdio.h>
#include <stdlib.h>

/*
Nakon lakšeg zemljotresa u jednom gradu u gradskoj biblioteci knjige su pale na pod sa
polica i izmešale se. Bibliotekari moraju da vrate knjige na police tako da one budu 
poređane leksikografski po svom nazivu. Pomoći bibliotekarima da poređaju knjige na police.
*/


// Resenje koriscenjem strukture podataka Trie (prefiksno stablo) - radi za mala slova

typedef struct Cvor 
{
    struct Cvor* deca[31];
    int krajReci;
} Cvor;

Cvor* noviCvor() {
    Cvor* cvor = (Cvor*) malloc(sizeof(Cvor));
    cvor->krajReci = 0;

    for(int i = 0; i < 30; i++) {
        cvor->deca[i] = NULL;
    }

    return cvor;
}

void ucitaj(Cvor* koren, const char* rec) {
    Cvor* tren = koren;

    while(*rec) {
        int slovo = *rec;
        if(slovo == ' ') {
            if(tren->deca[30] == NULL) {
                tren->deca[30] = noviCvor();
            }
            tren = tren->deca[30];
            rec++;
            continue;
        }
        if(tren->deca[slovo - 'a'] == NULL) {
            tren->deca[slovo - 'a'] = noviCvor();
        }
        tren = tren->deca[slovo - 'a'];
        rec++;
    }
    
    tren->krajReci = 1;
}

void odstampajRec(Cvor* cvor, char* pref, int dubina) {
    if(cvor->krajReci) {
        pref[dubina] = '\0';
        printf("%s\n", pref);
    }

    for(int i = 0; i < 31; i++) {
        if(cvor->deca[i] != NULL) {
            pref[dubina] = (i == 30) ? 32 : 'a' + i;
            odstampajRec(cvor->deca[i], pref, dubina + 1);
        }
    }
}

void odstampaj(Cvor* koren) {
    char prefiks[100];
    odstampajRec(koren, prefiks, 0);
}

void oslobodi(Cvor* koren) {
    for(int i = 0; i < 31; i++) {
        if(koren->deca[i] != NULL) {
            oslobodi(koren->deca[i]);
        }
    }
    free(koren);
}

int main() {
    int n;
    printf("Uneti broj knjiga:");
    scanf("%d", &n);
    getchar();

    Cvor* koren = noviCvor();
    char* str = malloc(50 * sizeof(char));

    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", str);
        getchar();
        ucitaj(koren, str);
    }

    printf("Sortirani naslovi knjiga:\n");
    odstampaj(koren);

    oslobodi(koren);

    return 0;
}