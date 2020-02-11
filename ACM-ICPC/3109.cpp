#include <cstdio>
using namespace std;

int r, c, answer;
int dx[] = { -1, 0, 1 }, dy[] = { 1, 1, 1 };
char arr[10001][501];
bool visited[10001][501];

int dfs(int x, int y) {
    visited[x][y] = true;

    if (y == c - 1) {
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (!visited[nx][ny] && arr[nx][ny] == '.') {
                int v = dfs(nx, ny);
                if (v == 1) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        answer += dfs(i, 0);
    }

    printf("%d\n", answer);
}