#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
int dist[21][21][21];
bool checked[21][21][21];
char map[21][21];
vector<pair<pair<int, int>, int> > trash;
int x, y;

void bfs(int x, int y, int pos) {
    queue<pair<int, int> > q;
    q.push({ x, y });
    dist[x][y][pos] = 0;
    checked[x][y][pos] = true;
    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!checked[nx][ny][pos] && map[nx][ny] != 'x') {
                    checked[nx][ny][pos] = true;
                    dist[nx][ny][pos] = dist[px][py][pos] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int main() {
    while (scanf(" %d %d", &m, &n) != -1) {
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                for (int k = 0; k < 21; k++) {
                    dist[i][j][k] = 1e5;
                }
            }
        }

        memset(checked, 0, sizeof(checked));
        memset(map, 0, sizeof(map));
        trash.clear();
        x = y = 0;
        int trashCount = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %1c", &map[i][j]);
                if (map[i][j] == '*') {
                    trash.push_back({ { i, j }, trashCount++ });
                }
                if (map[i][j] == 'o') {
                    x = i;
                    y = j;
                }
            }
        }

        int answer = 1e5;
        int count = trash.size();

        if (count == 0) {
            printf("0\n");
            continue;
        }

        bfs(x, y, 0);

        sort(trash.begin(), trash.end());
        for (int i = 0; i < count; i++) {
            bfs(trash[i].first.first, trash[i].first.second, trash[i].second);
        }
        do {
            int temp = dist[trash[0].first.first][trash[0].first.second][0];
            for (int i = 0; i < count - 1; i++) {
                temp += dist[trash[i + 1].first.first][trash[i + 1].first.second][trash[i].second];
            }
            answer = min(answer, temp);
        } while (next_permutation(trash.begin(), trash.end()));
        printf("%d\n", (answer == 1e5) ? -1 : answer);
    }
}