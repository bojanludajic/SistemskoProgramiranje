#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    char res[200];
    int duzina = strlen(str);
    int i = 0;
    int j = 0;
    while(i < duzina) {
        if(str[i] == 'x') {
            res[j++] = 'k';
            res[j++] = 's';
        } else {
            res[j] = str[i];
            j++;
        }
        i++;
    }
    printf("%s", res);

    return 0;
}