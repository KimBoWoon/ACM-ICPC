#include <bits/stdc++.h>

int arr[301], dp[301];
int n;

// // max(전전 칸 + 현재 칸, 전전전 칸 + 전 칸 + 현재 칸);
int topDown(int x) {
	if (x == 0) {
		return dp[x] = 0;
	}
	if (x == 1) {
		return dp[x] = arr[1];
	}
	if (x == 2) {
		return dp[x] = arr[1] + arr[2];
	}

	if (dp[x] > 0) {
		return dp[x];
	}

	dp[x] = std::max(topDown(x - 2) + arr[x], topDown(x - 3) + arr[x - 1] + arr[x]);

	return dp[x];
}

int bottomUp(int x) {
	for (int i = 1; i <= x; i++) {
		dp[i] = std::max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	return dp[x];
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	memset(dp, 0, sizeof(dp));
	printf("%d\n", topDown(n));
	// printf("%d\n", bottomUp(n));

	return 0;
}