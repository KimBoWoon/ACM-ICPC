//
// Created by null on 11/25/17.
//

#define LOCAL

#include <cstdio>

#define INF 987654321
#define VERTICES 101

int n, m, x, y;

int map[VERTICES][VERTICES];

int c[101][101], path[101][101];

void Floyd() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            path[i][j] = -1;
            c[i][j] = map[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void printPath(int a, int b) {
    if (path[a][b] != -1) {
        printPath(a, path[a][b]);
        printf("%d ", path[a][b]);
        printPath(path[a][b], b);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);

        map[x - 1][y - 1] = map[y - 1][x - 1] = 1;
    }

    Floyd();

    int maxValue = INF, ans = 0;
    for (int i = 0; i < n; ++i) {
        int minValue = 0;
        for (int j = 0; j < n; ++j) {
            minValue += (c[i][j] < INF) ? c[i][j] : 0;
        }
        if (minValue < maxValue) {
            maxValue = minValue;
            ans = i + 1;
        }
    }
    printf("%d\n", ans);
}