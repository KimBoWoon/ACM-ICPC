#include <cstdio>
#include <cstring>
using namespace std;

char cmd[10];
int n, m, num, dir, x, y;
int dx[] = { 1, 0, -1, 0}, dy[] = { 0, -1, 0, 1 };

void move(int i, int j, int k) {
    for (int a = 0; a < k; a++) {
        x += i;
        y += j;
    }
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", cmd, &num);

        if (strcmp(cmd, "TURN") == 0) {
            if (num == 0) {
                dir = (4 + --dir) % 4;
            } else if (num == 1) {
                dir = ++dir % 4;
            }
        } else if (strcmp(cmd, "MOVE") == 0) {
            move(dx[dir], dy[dir], num);

            if (x > m || x < 0 || y > m || y < 0) {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d %d\n", x, y);
}