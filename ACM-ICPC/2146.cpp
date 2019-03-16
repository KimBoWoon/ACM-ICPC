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
int bfs(int r, int c, int color) {
    memset(visit, 0, sizeof(visit));

    queue<point> q;
    q.push({ r, c });
    visit[r][c] = true;
    int way = 0;
    
    while (q.size()) {
        int size = q.size();
        while (size--) {
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

// 상, 하, 좌, 우로 이동할 수 있니?
bool go(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx > -1 && nx < n && ny > -1 && ny < n) {
            if (map[nx][ny] == 0) {
                return true;
            }
        }
    }
    return false;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 0 && go(i, j)) {
                answer = min(answer, bfs(i, j, map[i][j]));
            }
        }
    }

    printf("%d\n", answer);
}