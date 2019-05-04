#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[201][201];

int main() {
    for (int i = 0; i <= 200; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = min(c[i - 1][j - 1] + c[i - 1][j], (int)1e9);
        }
    }

    scanf("%d %d %d", &n, &m, &k);

    int len = n + m;

    if (k > c[len][n]) {
        printf("-1\n");
    } else {
        for (int i = 0; i < len; i++) {
            if (k > c[n + m - 1][m]) {
                printf("z");
                k -= c[n + m - 1][m];
                m--;
            }
            else {
                printf("a");
                n--;
            }
        }
        printf("\n");
    }
    return 0;
}