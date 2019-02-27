#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Point {
    int x, y;
} point;

char map[51][51];
int x, y, answer, dist;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int visit[51][51];
queue<point> q;

void printVisit() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
            printf("%d ", visit[i][j]);
		}
        printf("\n");
	}
    printf("\n");
}

void init() {
    dist = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (map[i][j] == 'L') {
                visit[i][j] = 1;
            } else {
                visit[i][j] = -1;
            }
        }
    }
}

void bfs() {
    while (!q.empty()) {
        int px = q.front().x, py = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];

            if (nx > -1 && nx < x && ny > -1 && ny < y) {
                if (visit[nx][ny] == 1) {
                    q.push({ nx, ny });
                    visit[nx][ny] = visit[px][py] + 1;
                }
            }
        }
    }
}

void check() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (visit[i][j] > dist) {
                dist = visit[i][j];
            }
        }
    }
}

int main() {
    scanf("%d %d", &x, &y);

    for (int i = 0; i < x; i++) {
        scanf("%s", map[i]);
    }

    // 시작점은 모든 육지
    // 제일 큰 값을 가져오면 된다
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (map[i][j] == 'L') {
                q.push({ i, j });
                visit[i][j] = 1;
                bfs();
                check();
                // printVisit();
                if (answer < dist) {
                    answer = dist;
                }
                init();
            }
        }
    }

    printf("%d\n", answer - 1);
}