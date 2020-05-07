#include <cstdio>
#include <cstring>
using namespace std;

int n, x, y;
int map[101][101];
long long dp[101][101];

bool check(int x, int y) {
	if (x < n && y < n) {
		return true;
	}
	return false;
}

long long jump(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		return 1;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	dp[x][y] = 0;

	if (check(x + map[x][y], y)) {
		dp[x][y] += jump(x + map[x][y], y);
	}

	if (check(x, y + map[x][y])) {
		dp[x][y] += jump(x, y + map[x][y]);
	}

	return dp[x][y];
}

// void jump() {
// 	dp[0][0] = 1;

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (i == n - 1 && j == n - 1) {
// 				continue;
// 			}

// 			x = map[i][j] + i;
// 			y = map[i][j] + j;

// 			if (x < n) {
// 				dp[x][j] += dp[i][j];
// 			}
// 			if (y < n) {
// 				dp[i][y] += dp[i][j];
// 			}
// 		}
// 	}
// }

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));

	// jump();

	printf("%lld\n", jump(0, 0));
	// printf("%lld\n", dp[n - 1][n - 1]);
}