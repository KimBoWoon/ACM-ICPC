#include <cstdio>
using namespace std;

int arr[16][16], dp[16][16];
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

	if (n == 0) { // O 표시가 없는 경우
		dp[1][1] = 1; // 시작 지점
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		printf("%d\n", dp[row][col]);
	} else {
		dp[1][1] = 1;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		int sum1 = dp[x][y];
		dp[x][y] = 1;
		for (int i = x; i <= row; i++) {
			for (int j = y; j <= col; j++) {
				if (i == x && j == y) {
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		int sum2 = dp[row][col];

		printf("%d\n", sum1 * sum2);
	}

	return 0;
}

// O 표시가 없는 경우
// 1, 1 에서 x, y까지의 경우의 수 * x, y 에서 row, col까지의 경우의 수