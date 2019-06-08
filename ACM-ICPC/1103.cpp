#include <bits/stdc++.h>

char map[51][51];
bool visited[51][51];
int n, m;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int dp[51][51];

int topDown(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return 0;
    }
    if (map[x][y] == 'H') {
        return 0;
    }
    if (visited[x][y]) {
        return -1;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + ((map[x][y] - '0') * dx[i]);
        int ny = y + ((map[x][y] - '0') * dy[i]);
        dp[x][y] = std::max(dp[x][y], topDown(nx, ny) + 1);
    }
    visited[x][y] = false;

    return dp[x][y];
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%d\n", topDown(0, 0));
}