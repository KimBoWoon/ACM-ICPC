#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Point {
    int x, y, broken;

    friend bool operator< (const Point x, const Point y) {
        return y.broken < x.broken;
    }
} point;

char map[101][101];
int n, m;
bool visited[101][101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int bfs(int x, int y) {
    priority_queue<point> pq;

    visited[x][y] = true;
    pq.push({ x, y, 0 });

    while (!pq.empty()) {
        point p = pq.top();
        pq.pop();

        if (p.x == m - 1 && p.y == n - 1) {
            return p.broken;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!visited[nx][ny]) {
                    if (map[nx][ny] == '1') {
                        pq.push({ nx, ny, p.broken + 1 });
                    } else {
                        pq.push({ nx, ny, p.broken });
                    }
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        scanf("%s", map[i]);
    }

    printf("%d\n", bfs(0, 0));
}

// 우선순위 큐를 사용해 부숴버린 벽 순으로 오름차순 정렬
// 그리고 bfs를 구현하면 쉽게 풀리는 문제