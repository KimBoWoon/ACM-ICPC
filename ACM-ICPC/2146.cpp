#include <cstdio>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAX 101

typedef struct Point {
    int x, y;
} point;

int n;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int map[MAX][MAX];
bool visit[MAX][MAX];

void printVisit() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 각각의 섬을 다른 숫자로 표시
void dfs(int r, int c, int color) {
    visit[r][c] = true;

    map[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int nx = r + dx[i], ny = c + dy[i];

        if (nx > -1 && nx < n && ny > -1 && ny < n) {
            if (!visit[nx][ny] && map[nx][ny] == 1) {
                dfs(nx, ny, color);
            }
        }
    }
}

// 한 섬에서 다른 섬으로의 경로를 만든다
int bfs(int color) {
    queue<point> q;

    // color로 표시된 섬의 좌표를 모두 추가한다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == color) {
                visit[i][j] = true;
                q.push({ i, j });
            }
        }
    }

    int way = 0;

    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
            point p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];

                if (nx > -1 && nx < n && ny > -1 && ny < n) {
                    if (map[nx][ny] != 0 && map[nx][ny] != color) {
                        return way;
                    }
                    if (map[nx][ny] == 0 && !visit[nx][ny]) {
                        visit[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        way++;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int color = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visit[i][j]) {
                dfs(i, j, color++);
            }
        }
    }

    int answer = 987654321;
    for (int i = 1; i < color; i++) {
        memset(visit, 0, sizeof(visit));
        answer = min(answer, bfs(i));
    }

    printf("%d\n", answer);
}