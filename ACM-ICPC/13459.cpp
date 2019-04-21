#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

bool flag;
int n, m, answer;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
char map[11][11];
bool visited[11][11][11][11];
queue<point> r, b;

void move(int& nx, int& ny, int x, int y) {
    while (true) {
        if (map[nx][ny] == '#') {
            nx -= x;
            ny -= y;
            break;
        }
        if (map[nx][ny] == 'O') {
            break;
        }
        nx += x;
        ny += y;
    }
}

void bfs() {
    visited[r.front().x][r.front().y][b.front().x][b.front().y] = true;

    while (!r.empty()) {
        int size = r.size();
        while (size--) {
            point rHere = r.front(), bHere = b.front();
            r.pop(), b.pop();

            if (answer > 10) {
                break;
            }
            if (map[rHere.x][rHere.y] == 'O') {
                flag = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int rNx = rHere.x + dx[i], rNy = rHere.y + dy[i];
                int bNx = bHere.x + dx[i], bNy = bHere.y + dy[i];

                move(rNx, rNy, dx[i], dy[i]);
                move(bNx, bNy, dx[i], dy[i]);

                if (map[bNx][bNy] == 'O') {
                    continue;
                }
                if (rNx == bNx && rNy == bNy) {
                    switch (i) {
                        case 0: 
                            (rHere.x > bHere.x) ? rNx++ : bNx++; 
                            break;
                        case 1: 
                            (rHere.x < bHere.x) ? rNx-- : bNx--; 
                            break;
                        case 2: 
                            (rHere.y > bHere.y) ? rNy++ : bNy++; 
                            break;
                        case 3: 
                            (rHere.y < bHere.y) ? rNy-- : bNy--; 
                            break;
                    }
                }
                if (visited[rNx][rNy][bNx][bNy]) {
                    continue;
                }
                r.push({ rNx, rNy });
                b.push({ bNx, bNy });
                visited[rNx][rNy][bNx][bNy] = true;
            }
        }
        if (flag) {
            return;
        } else {
            answer++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            scanf(" %c", &temp);
            map[i][j] = temp;
            if (temp == 'R') {
                r.push({ i, j });
            }
            if (temp == 'B') {
                b.push({ i, j });
            }
        }
    }

    bfs();

    if (flag) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}