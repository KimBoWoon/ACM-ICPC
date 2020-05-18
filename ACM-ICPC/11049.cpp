#include <bits/stdc++.h>
using namespace std;

typedef struct Matrix {
    int r, c;
} matrix;

int n;
int dp[501][501];
matrix m[501];

int f(int x, int y) {
    if (x == y) {
        return 0;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 2e9;
    for (int i = x; i < y; i++) {
        dp[x][y] = min(dp[x][y], f(x, i) + f(i + 1, y) + m[x].r * m[i].c * m[y].c);
    }

    return dp[x][y];
}

int bottomUp() {
    for (int r = 1; r < n; r++) {
        for (int i = 0, j = i + r; i < n - r; i++, j++) {
            dp[i][j] = 2e9;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i].r * m[k].c * m[j].c);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i].r, &m[i].c);
    }

    memset(dp, -1, sizeof(dp));

    printf("%d\n", f(0, n - 1));
    // printf("%d\n", bottomUp());
}