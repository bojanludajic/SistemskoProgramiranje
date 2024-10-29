#include <stdio.h>

#define pi 3.14

void krug(float r, float *p, float *o) {
    *p = r * r * pi;
    *o = 2 * r * pi;
}

int main() {
    float r;
    float p;
    float o;
    scanf("%f", &r);
    krug(r, &p, &o);
    printf("%f\n", p);
    printf("%f", o);
    return 0;
}