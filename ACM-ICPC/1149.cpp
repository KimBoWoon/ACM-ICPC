#include <bits/stdc++.h>

int n;
int arr[1001][3], dp[1001][3];
int minCost;

int topDown(int x) {
	if (x == 0) {
		dp[x][0] = arr[x][0];
		dp[x][1] = arr[x][1];
		dp[x][2] = arr[x][2];
		return 0;
	}

	topDown(x - 1);

	dp[x][0] = std::min(dp[x - 1][1], dp[x - 1][2]) + arr[x][0];
	dp[x][1] = std::min(dp[x - 1][0], dp[x - 1][2]) + arr[x][1];
	dp[x][2] = std::min(dp[x - 1][0], dp[x - 1][1]) + arr[x][2];

	return std::min(dp[x - 1][0], std::min(dp[x - 1][1], dp[x - 1][2]));
}

int bottomUp(int x) {
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < x; i++) {
		dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	return std::min(dp[x - 1][0], std::min(dp[x - 1][1], dp[x - 1][2]));
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	printf("%d\n", topDown(n));
	// printf("%d\n", bottomUp(n));

	return 0;
}