#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[16][16], d[16][16];
int row, col, n, cnt, x, y;

int main() {
	scanf("%d %d %d", &row, &col, &n);

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			arr[i][j] = ++cnt;
			if (cnt == n) {
				x = i;
				y = j;
			}
		}
	}

	if (n == 0) {
		d[1][1] = 1;
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			}
		}

		printf("%d\n", d[row][col]);
	}
	else {
		d[1][1] = 1;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			}
		}

		int sum1 = d[x][y];
		d[x][y] = 1;
		for (int i = x; i <= row; i++) {
			for (int j = y; j <= col; j++) {
				if (i == x && j == y) {
					continue;
				}
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			}
		}

		int sum2 = d[row][col];

		printf("%d\n", sum1 * sum2);
	}

	return 0;
}