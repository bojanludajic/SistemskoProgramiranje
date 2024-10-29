#include <stdio.h>

int nzd(int a, int b);
int nzs(int a, int b);

int main() {
    int nzdd = nzd(10, 50);
    int nzss = nzs(10, 35);
    printf("%d\n", nzdd);
    printf("%d", nzss);
    return 0;
}

int nzd(int a, int b) {
    while(a != b) {
        if(a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int nzs(int a, int b) {
    return (a * b) / nzd(a, b);
}