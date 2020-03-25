#include <cstdio>
using namespace std;

int n, m, answer = 987654321;
char board[51][51];
//(0, 0)이 W인 체스보드
char whiteFirst[8][8] = {
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }
};
//(0, 0)이 B인 체스보드
char blackFirst[8][8] = {
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
        { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
        { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' }
};

int f(int x, int y) {
    int white = 0, black = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != whiteFirst[i - x][j - y]) {
                white++;
            }
        }
    }

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != blackFirst[i - x][j - y]) {
                black++;
            }
        }
    }

    return (white < black) ? white : black;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%c", board[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int value = f(i, j);
            if (answer > value) {
                answer = value;
            }
        }
    }

    printf("%d\n", answer);
}