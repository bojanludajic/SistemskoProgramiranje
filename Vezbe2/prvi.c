#include <stdio.h>

int main() {
    int n;
    int m;
    int p;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);
    int prvi[n][m];
    int drugi[m][p];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &prvi[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            scanf("%d", &drugi[i][j]);
        }
    }
    int rez[n][p];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            rez[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < m; k++) {
                rez[i][j] += (prvi[i][k] * drugi[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            printf("%d ", rez[i][j]);
        }
        printf("\n");
    }

    return 0;
}