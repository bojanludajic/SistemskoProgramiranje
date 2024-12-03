#include <stdio.h>
#include <stdlib.h>

int mladji_od_50_iskusni = 0;

typedef struct {
    char ime[50];
    char prezime[100];
    int godine;
    int godine_iskustva;
} osoba_t;

void ucitaj_osobe(osoba_t osobe[], int n) {
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", osobe[i].ime);
        getchar();
        scanf("%[^\n]s", osobe[i].prezime);
        getchar();
        scanf("%d", &osobe[i].godine);
        getchar();
        scanf("%d", &osobe[i].godine_iskustva);
        getchar();
    }
}

float prosek_godine(osoba_t niz[], int n) {
    float zbir = 0;

    for(int i = 0; i < n; i++) {
        zbir += niz[i].godine;
    }

    return zbir / n;
}

float prosek_radnog_staza(osoba_t niz[], int n) {
    float zbir = 0;

    for(int i = 0; i < n; i++) {
        zbir += niz[i].godine_iskustva;
    }

    return zbir / n;
}

osoba_t* izdvoj(osoba_t niz[], int n) {
    osoba_t* res = malloc(n * sizeof(osoba_t));
    int j = 0;

    for(int i = 0; i < n; i++) {
        if(niz[i].godine < 50 && niz[i].godine_iskustva > 20) {
            mladji_od_50_iskusni++;
            *(res + j) = niz[i];
            j++;
        }
    }

    return res;
}

void ispisi_osobe(osoba_t niz[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Ime: %s, prezime: %s, godine: %d, iskustvo: %d\n",
            niz[i].ime,
            niz[i].prezime,
            niz[i].godine,
            niz[i].godine_iskustva
        );
    }
}

int main() {
    printf("Unesite broj osoba: ");
    int n;
    scanf("%d", &n);
    getchar();

    osoba_t* osobe = malloc(n * sizeof(osoba_t));

    ucitaj_osobe(osobe, n);

    ispisi_osobe(osobe, n);

    osoba_t* izdvojeni = izdvoj(osobe, n);

    printf("Osobe mladje od 50 godina, sa preko 20 godina staza:\n");
    ispisi_osobe(izdvojeni, mladji_od_50_iskusni);
    
    printf("Proescna starost: %f\n", prosek_godine(osobe, n));
    printf("Prosecan radni staz: %f\n", prosek_radnog_staza(osobe, n));

    return 0;
}