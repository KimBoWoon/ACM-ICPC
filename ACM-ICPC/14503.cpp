#include <cstdio>
using namespace std;

int n, m, r, c, d, turn, answer;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int map[51][51];

void clean(int r, int c, int d) {
    while (true) {
        map[r][c] = 2;
        d = (d + 3) % 4;
        turn++;

        int nx = r + dx[d], ny = c + dy[d];

        if (nx > -1 && nx < n && ny > -1 && ny < m) {
            // 청소
            if (map[nx][ny] == 0) {
                answer++;
                r = nx;
                c = ny;
                turn = 0;
                continue;
            } else if (map[nx][ny] != 0) { // 청소할 공간이 없다
                // 네 방향 모두 탐색
                if (turn >= 4) {
                    if (d == 0) {
                        nx = r + dx[2];
                        ny = c + dy[2];
                    } else if (d == 1) {
                        nx = r + dx[3];
                        ny = c + dy[3];
                    } else if (d == 2) {
                        nx = r + dx[0];
                        ny = c + dy[0];
                    } else if (d == 3) {
                        nx = r + dx[1];
                        ny = c + dy[1];
                    }

                    // 맵을 벗어나거나 후진을 못하면 종료
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1) {
                        return;
                    } else { // 후진
                        r = nx;
                        c = ny;
                        turn = 0;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    clean(r, c, d);

    printf("%d\n", answer + 1);
}