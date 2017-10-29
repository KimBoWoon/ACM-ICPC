//
// Created by null on 10/29/17.
//

#define LOCAL

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef struct Point {
    int x, y;
} point;

int n, minHeight = 999999999, maxHeight = -1, ans = 1, result;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int map[101][101];
bool mark[101][101];

void bfs(point v) {
    queue<point> q;
    q.push(v);
    mark[q.front().x][q.front().y] = true;

    while (!q.empty()) {
        point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if (nx > -1 && nx < n && ny > -1 && ny < n) {
                if (map[nx][ny] != 0 && !mark[nx][ny]) {
                    q.push({nx, ny});
                    mark[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    // 입력값의 최소값과 최대값만 구해서 그 구간만 돌리면 더 빠르다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] > maxHeight) {
                maxHeight = map[i][j];
            }
            if (map[i][j] < minHeight) {
                minHeight = map[i][j];
            }
        }
    }

    for (int c = minHeight; c < maxHeight; c++) {
        result = 0;
        memset(mark, 0, sizeof(mark));

        // 물에 잠기는 곳은 0으로 표시
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] <= c) {
                    map[i][j] = 0;
                }
            }
        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                printf("%d ", map[i][j]);
//            }
//            printf("\n");
//        }
//        printf("---------------------\n");
        // 물에 잠기지 않았고 방문하지 않았다면 방문해서 bfs를 실행
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != 0 && !mark[i][j]) {
                    bfs({i, j});
                    result++;
                }
            }
        }
        if (ans < result) {
            ans = result;
        }
    }

    printf("%d\n", ans);
}