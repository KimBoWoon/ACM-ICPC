#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Point {
    int x, y;
} point;

char map[51][51];
int l, w, answer;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int visited[51][51];

void printvisited() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
            printf("%d ", visited[i][j]);
		}
        printf("\n");
	}
    printf("\n");
}

void init() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'L') {
                visited[i][j] = 0;
            } else {
                visited[i][j] = -1;
            }
        }
    }
}

void bfs(int x, int y) {
    queue<point> q;
    q.push({ x, y });
    visited[x][y] = 0;

    while (!q.empty()) {
        point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];

            if (nx >= 0 && nx < l && ny >= 0 && ny < w) {
                if (map[nx][ny] == 'W' || (nx == x && ny == y)) {
                    continue;
                }
                if (visited[nx][ny] == 0 || visited[nx][ny] > visited[p.x][p.y] + 1) {
                    q.push({ nx, ny });
                    visited[nx][ny] = visited[p.x][p.y] + 1;
                }
            }
        }
    }
}

int check() {
    int dist = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (visited[i][j] > dist) {
                dist = visited[i][j];
            }
        }
    }

    return dist;
}

int main() {
    scanf("%d %d", &l, &w);

    for (int i = 0; i < l; i++) {
        scanf("%s", map[i]);
    }

    // 시작점은 모든 육지
    // 제일 큰 값을 가져오면 된다
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'L') {
                init();
                bfs(i, j);
                // printvisited();
                answer = max(answer, check());
            }
        }
    }

    printf("%d\n", answer);
}