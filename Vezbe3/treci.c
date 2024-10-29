#include <stdio.h>
#include <math.h>

void fun(int n, int *a, int *b) {
    for(int i = sqrt(n); i >= 1; i--) {
        if(n % i == 0) {
            *a = i;
            *b = n / i;
            return;
        }
    }
}

int main() {
    int n;
    int a;
    int b;
    scanf("%d", &n);
    fun(n, &a, &b);
    printf("%d %d", a, b);

    return 0;
}