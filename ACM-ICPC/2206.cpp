#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001], visited[1001][1001][2];
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0][1] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return visited[x][y][wall];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (0 <= ny && ny < m && 0 <= nx && nx < n) {
                if (map[nx][ny] == 1 && wall) { //벽이 있고, 벽을 아직 안 뚫었다면
                    visited[nx][ny][wall - 1] = visited[x][y][wall] + 1;
                    q.push(make_pair(make_pair(nx, ny), wall - 1));
                } else if (map[nx][ny] == 0 && visited[nx][ny][wall] == 0) { //벽이 없고 방문하지 않았던 곳이라면
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                    q.push(make_pair(make_pair(nx, ny), wall));
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    printf("%d\n", bfs());
}