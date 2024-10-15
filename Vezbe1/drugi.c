#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    while(n > 0) {
        res += n % 10;
        res *= 10;
        n /= 10;
    }
    printf("%d", res/10);
    return 0;
}