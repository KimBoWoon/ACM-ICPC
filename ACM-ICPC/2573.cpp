#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 301

typedef struct Point {
    int x, y;
} point;

bool flag;
int n, m, cnt, answer, split;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0};
int map[MAX][MAX], visit[MAX][MAX];

void printVisit() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%6d", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nextYear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (map[i][j] != 0) {
                    int nx = i + dx[k], ny = j + dy[k];

                    if (map[nx][ny] == 0) {
                        cnt++;
                    }
                }
            }

            if (map[i][j] - cnt < 0) {
                visit[i][j] = 0;
            } else {
                visit[i][j] = map[i][j] - cnt;
            }
            cnt = 0;
        }
    }
}

void bfs(int x, int y) {
    queue<point> q;
    q.push({ x, y });

    while (!q.empty()) {
        point now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];

            if (nx > -1 && nx < n && ny > -1 && ny < m) {
                if (visit[nx][ny] != 0) {
                    q.push({ nx, ny });
                    visit[nx][ny] = 0;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (true) {
        nextYear();
        memcpy(map, visit, sizeof(map));
        split = 0;
        answer++;
        flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] != 0) {
                    bfs(i, j);
                    // printf("i : %d, j : %d\n", i, j);
                    // printVisit();
                    split++;
                    flag = true;
                }
            }
        }

        if (!flag) {
            printf("0\n");
            break;
        }
        if (split >= 2) {
            printf("%d\n", answer);
            break;
        }
    }
}