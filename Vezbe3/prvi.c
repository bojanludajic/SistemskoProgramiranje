 #include <stdio.h>

const float g = 9.81;

void brzinaPadanja(int t, float *v, float *h) {
   *v = t * g;
   *h = (g * t * t) / 2;
}

int main() {
    int t;
    scanf("%d", &t);
    float v;
    float h;
    brzinaPadanja(t, &v, &h);
    printf("%f\n", v);
    printf("%f", h);
    return 0;
}