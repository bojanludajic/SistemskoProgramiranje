#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    char c;
    scanf("\n%c", &c);
    int broj = 0;
    int duzina = strlen(str);
    for(int i = 0; i < duzina; i++) {
        if(str[i] == c) {
            broj++;
        }
    }
    printf("%d", broj);
    return 0;
}