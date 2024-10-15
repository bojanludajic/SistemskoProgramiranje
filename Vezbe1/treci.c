#include <stdio.h>

int main() {
    int n;
    printf("Unesi n:");
    scanf("%d", &n);
    int visina = 2 * (n - 1) - 1;
    int sirina = 2 * n - 1;
    for(int i = 0; i < visina; i++) {
        for(int j = 0; j < sirina; j++) {
            if(i == n - 2) {
                if(j == n - 1) {
                    printf("@\n");
                    break;
                } else {
                    printf(" ");
                }
            } else if(i % 2 == 0) {
                if(j == n - 2) {
                    if(i < n - 2) {
                        printf("\\");
                    } else {
                        printf("/");
                    }
                } else if(j == n) {
                    if(i < n - 2) {
                        printf("/");
                    } else {
                        printf("\\");
                    }
                } else if(j == n - 1) {
                    printf(" ");
                } else {
                    printf("*");
                }
                if(j == sirina - 1) {
                    printf("\n");
                }
            } else {
                if(j == n - 2) {
                    if(i < n - 2) {
                        printf("\\");
                    } else {
                        printf("/");
                    }
                } else if(j == n) {
                    if(i < n - 2) {
                        printf("/");
                    } else {
                        printf("\\");
                    }
                } else if(j == n - 1) {
                    printf(" ");
                } else {
                    printf("-");
                }
                if(j == sirina - 1) {
                    printf("\n");
                }
            }
        }
    }
}