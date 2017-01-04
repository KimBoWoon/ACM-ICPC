//
// Created by secret on 1/4/17.
//

#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int map[501][501];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int m, n;

int dp(int x, int y) {
    int ans = 0;

    if (x == m && y == n) {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (x + dx[i] > m && y + dy[i] > n && x + dx[i] < 1 && y + dy[i] < 1) {
            return 0;
        }
        if (map[x + dx[i]][y + dy[i]] < map[x][y]) {
            ans += dp(x + dx[i], y + dy[i]);
        }
    }

    return ans;
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    printf("%d\n", dp(1, 1));
}