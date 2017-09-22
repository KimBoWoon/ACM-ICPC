#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans = -1;
int map[501][501], dp[501][501];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int move(int x, int y) {
	if (dp[x][y] == 0) {
		dp[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (ny < 0 || nx < 0 || ny > n || nx > n) {
				continue;
			}
			if (map[x][y] >= map[nx][ny]) {
				continue;
			}

			dp[x][y] = max(dp[x][y], move(nx, ny) + 1);
		}
	}

	return dp[x][y];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(move(i, j), ans);
		}
	}

	printf("%d\n", ans);
}