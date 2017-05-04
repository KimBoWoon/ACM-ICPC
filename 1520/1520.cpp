#include <cstdio>
using namespace std;

int map[501][501], ans[501][501];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int m, n;

int dp(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n) {
		return 0;
	}
	if (ans[x][y] >= 0) {
		return ans[x][y];
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (map[x][y] > map[x + dx[i]][y + dy[i]]) {
			ret += dp(x + dx[i], y + dy[i]);
		}
	}

	return ans[x][y] = ret;
}

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			ans[i][j] = -1;
		}
	}

	ans[m - 1][n - 1] = 1;

	printf("%d\n", dp(0, 0));

	return 0;
}