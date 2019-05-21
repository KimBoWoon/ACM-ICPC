#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

char map[51][51];
int r, c;
int dx[] = { 0, 1, 0, -1}, dy[] = { -1, 0, 1, 0 };
queue<point> water, q;

void bfs1() {
    int qsize = water.size();

    while (qsize--) {
        point here = water.front();
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nx = here.x + dx[i], ny = here.y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (map[nx][ny] == '.') {
                    water.push({ nx, ny });
                    map[nx][ny] = '*';
                }
            }
        }
    }
}

bool bfs2() {
    int qsize = q.size();

    while (qsize--) {
        point here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = here.x + dx[i], ny = here.y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (map[nx][ny] == '.') {
                    q.push({ nx, ny });
                    map[nx][ny] = 'S';
                }
                if (map[nx][ny] == 'D') {
                    q.push({ nx, ny });
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);

            if (map[i][j] == '*') {
                water.push({ i, j });
            } else if (map[i][j] == 'S') {
                q.push({ i, j });
            }
        }
    }

    int answer = 0;
    while (true) {
        answer++;

        if (q.size() == 0) {
            printf("KAKTUS\n");
            return 0;
        }

        bfs1();

        if (bfs2()) {
            printf("%d\n", answer);
            return 0;
        }
    }
}