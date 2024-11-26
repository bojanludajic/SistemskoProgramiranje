#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prebroj(char *s) {
    int i = 0;
    int count = 0;
    while(s[i] != '\0') {
        char c = s[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char *s = malloc(50 * sizeof(char));
    int count = 0;
    do {
        scanf("%[^\n]s", s);
        getchar();
        count += prebroj(s);
    }while(strcmp(s, "stop") != 0);
    printf("Uneto je: %d slova.", (count - 4));
    return 0;
}