#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LLONG;

int n, m;
int dx[] = { 0, 1, 0 }, dy[] = { 1, 0, -1 };
int map[1001][1001];
LLONG dp[3][1001][1001];
bool visited[1001][1001];

int f1(int dir, int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return map[x][y];
    }

    if (dp[dir][x][y] != -2e9) {
        return dp[dir][x][y];
    }

    visited[x][y] = true;

    LLONG a = -2e9, b = -2e9, c = -2e9;
    if (y - 1 >= 0 && !visited[x][y - 1]) {
        a = f1(0, x, y - 1);
    }
    if (y + 1 < m && !visited[x][y + 1]) {
        b = f1(1, x, y + 1);
    }
    if (x + 1 < n && !visited[x + 1][y]) {
        c = f1(2, x + 1, y);
    }

    visited[x][y] = false;
    return dp[dir][x][y] = map[x][y] + max(max(a, b), c);
}

LLONG f2(int dir, int x, int y) {
    if (x == n - 1 && y == m - 1) { // 도착지에 도착했으면
        return map[x][y];
    }

    if (dp[dir][x][y] != -2e9) { // 이미 값이 저장되어 있으면
        return dp[dir][x][y];
    }

    visited[x][y] = true; // 방문
    for (int i = 0; i < 3; i++) { // 삼방향 탐색
        int nx = x + dx[i], ny = y + dy[i]; // 다음 방향 (오른쪽(0), 아래쪽(1), 왼쪽(2))

        if (nx > -1 && nx < n && ny > -1 && ny < m) { // 범위안에 있으면
            if (!visited[nx][ny]) { // 방문하지 않았으면
                dp[dir][x][y] = max(dp[dir][x][y], map[x][y] + f2(i, nx, ny)); // 각 방향마다 최대값을 저장
            }
        }
    }
    visited[x][y] = false; // 다음 차례를 위해 방문하지 않은걸로 표시

    return dp[dir][x][y];
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
    printf("%d\n", f2(0, 0, 0));
}