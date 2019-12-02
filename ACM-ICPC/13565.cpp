#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int dx[] = { 1, 0, -1, 0}, dy[] = { 0, 1, 0, -1 };
int map[1001][1001];
bool visited[1001][1001];

void bfs(int start) {
    queue<pair<int, int> > q;

    visited[0][start] = true;
    map[0][start] = 2;
    q.push({ 0, start });

    while (!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + here.first, ny = dy[i] + here.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && map[nx][ny] == 0) {
                    q.push({ nx, ny });
                    map[nx][ny] = 2;
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        if (map[0][i] == 0) {
            bfs(i);
        }
    }

    for (int i = 0; i < m; i++) {
        if (map[n - 1][i] == 2) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
}