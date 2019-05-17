#include <bits/stdc++.h>

int arr[2][100001], dp[2][100001];
int t, n, answer;

int topDown(int y, int x) {
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[0][x] = std::max(topDown(0, x - 1), topDown(1, x - 1) + arr[0][x]);
	dp[1][x] = std::max(topDown(1, x - 1), topDown(0, x - 1) + arr[1][x]);

	return std::max(dp[0][x - 1], dp[1][x - 1]);
}

int bottomUp(int x) {
	for (int i = 0; i < x; i++) {
		dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1] + arr[0][i]);
		dp[1][i] = std::max(dp[1][i - 1], dp[0][i - 1] + arr[1][i]);
	}

	return std::max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		memset(dp, 0, sizeof(dp));
		// printf("%d\n", topDown(n, n));
		printf("%d\n", bottomUp(n));
	}

	return 0;
}