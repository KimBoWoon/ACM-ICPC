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

    int& r = dp[x][y];
    if (r != -1) {
        return r;
    }

    int a = 2e9;

    for (int i = x; i < y; i++) {
        a = min(a, f(x, i) + f(i + 1, y) + m[x].r * m[i].c * m[y].c);
    }

    return r = a;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i].r, &m[i].c);
    }

    memset(dp, -1, sizeof(dp));

    printf("%d\n", f(0, n - 1));
}