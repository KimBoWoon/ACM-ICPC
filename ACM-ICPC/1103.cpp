#include <bits/stdc++.h>

char map[51][51];
bool cycle;
bool visited[51][51];
int n, m, answer;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int dp[51][51];

int topDown(int x, int y) {
    // 맵 범위 확인
    if (x >= n || x < 0 || y >= m || y < 0) {
        return 0;
    }

    // 구멍
    if (map[x][y] == 'H') {
        return 0;
    }

    // 무한으로 움직일 수 있다
    if (visited[x][y]) {
        cycle = true;
        return -1;
    }

    // 메모이제이션
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

    answer = topDown(0, 0);

    if (cycle) {
        printf("-1\n");
    } else {
        printf("%d\n", answer);
    }
}