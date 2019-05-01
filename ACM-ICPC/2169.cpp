#include <bits/stdc++.h>

typedef long long LLONG;

int n, m;
int map[1001][1001];
LLONG dp[3][1001][1001];
bool visited[1001][1001];

int f(int dir, int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return map[x][y];
    }

    LLONG& ret = dp[dir][x][y];

    if (ret != -2e9) {
        return ret;
    }

    visited[x][y] = true;

    LLONG a = -2e9, b = -2e9, c = -2e9;
    if (y - 1 >= 0 && !visited[x][y - 1]) {
        a = f(0, x, y - 1);
    }
    if (y + 1 < m && !visited[x][y + 1]) {
        b = f(1, x, y + 1);
    }
    if (x + 1 < n && !visited[x + 1][y]) {
        c = f(2, x + 1, y);
    }

    visited[x][y] = false;
    return ret = map[x][y] + std::max(std::max(a, b), c);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = -2e9;
        }
    }

    memset(visited, false, sizeof(visited));
    printf("%d\n", f(0, 0, 0));
}