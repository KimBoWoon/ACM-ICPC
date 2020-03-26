#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef struct Point {
    int x, y, z, move;
} point;

int l, r, c, answer;
int dx[] = { 0, 1, 0, -1, 0, 0 }, dy[] = { 1, 0, -1, 0, 0, 0 }, dz[] = { 0, 0, 0, 0, 1, -1 };
char arr[31][31][31];
bool visited[31][31][31];
point start, destination;

// bfs가 3차원으로 늘어난 문제
// 간단한 bfs 탐색이다
int bfs(point start) {
    queue<point> q;
    q.push(start);
    visited[start.z][start.x][start.y] = true;

    while (!q.empty()) {
        point value = q.front();
        q.pop();

        if (value.x == destination.x && value.y == destination.y && value.z == destination.z) {
            printf("Escaped in %d minute(s).\n", value.move);
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            int nx = value.x + dx[i], ny = value.y + dy[i], nz = value.z + dz[i];

            if (nx > -1 && nx < r && ny > -1 && ny < c && nz > -1 && nz < l) {
                if (!visited[nz][nx][ny] && arr[nz][nx][ny] != '#') {
                    q.push({ nx, ny, nz, value.move + 1 });
                    visited[nz][nx][ny] = true;
                }
            }
        }
    }

    return -1;
}

int main() {
    while (true) {
        memset(visited, false, sizeof(visited));
        memset(arr, 0, sizeof(arr));

        scanf("%d %d %d", &l, &r, &c);

        if (l == 0 && r == 0 && c == 0) {
            return 0;
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    scanf(" %c", &arr[i][j][k]);

                    if (arr[i][j][k] == 'S') {
                        start.x = j;
                        start.y = k;
                        start.z = i;
                        start.move = 0;
                    }
                    if (arr[i][j][k] == 'E') {
                        destination.x = j;
                        destination.y = k;
                        destination.z = i;
                        destination.move = 0;
                    }
                }
            }
        }

        if (bfs(start) == -1) {
            printf("Trapped!\n");
        }

        // for (int i = 0; i < l; i++) {
        //     for (int j = 0; j < r; j++) {
        //         for (int k = 0; k < c; k++) {
        //             printf("%c", arr[i][j][k]);
        //         }
        //         printf("\n");
        //     }
        //     printf("\n");
        // }
    }
}