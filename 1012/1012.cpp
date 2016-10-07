//
// Created by secret on 10/6/16.
//

#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;

int roomSize(int arr[51][51], int x, int y, int row, int col);

int arr[51][51];

int main() {
    int testCase;

    scanf("%d", &testCase);

    while (testCase--) {
        int row, col, cnt, size, a = 0;

        scanf("%d %d %d", &row, &col, &cnt);

        for (int i = 0; i < cnt; i++) {
            int x, y;

            scanf("%d %d", &x, &y);

            arr[y][x] = 1;
        }
        for (int x = 0; x < col; x++) {
            for (int y = 0; y < row; y++) {
                size = roomSize(arr, x, y, col, row);
                if (size != 0)
                    a++;
            }
        }
        printf("%d\n", a);
    }
}

int roomSize(int arr[51][51], int x, int y, int row, int col) {
    int count = 0;

    if ((x > 0 && y > 0) && (x < row && y < col)) {
        if (arr[x][y] == 1) {
            count++;
            arr[x][y] = 0;
            if (arr[x][y + 1] != 0 || arr[x + 1][y] != 0 || arr[x][y - 1] != 0 || arr[x - 1][y] != 0) {
                count += roomSize(arr, x, y + 1, row, col);
                count += roomSize(arr, x, y - 1, row, col);
                count += roomSize(arr, x + 1, y, row, col);
                count += roomSize(arr, x - 1, y, row, col);
            }
        }
    }
    return count;
}