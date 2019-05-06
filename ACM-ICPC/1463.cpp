#include <bits/stdc++.h>

int n;
int dp[1000001];

// dp[x라는 수를 1로 만드는 최소 횟수]
int topDown(int x) {
	if (x == 1) {
		return 0;
	}

	if (dp[x] > 0) {
		return dp[x];
	}

	dp[x] = topDown(x - 1) + 1;

	if (x % 2 == 0) {
		dp[x] = std::min(dp[x], topDown(x / 2) + 1);
	}
	if (x % 3 == 0) {
		dp[x] = std::min(dp[x], topDown(x / 3) + 1);
	}

	return dp[x];
}

int bottomUp(int x) {
	for (int i = 1; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = std::min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = std::min(dp[i], dp[i / 3] + 1);
		}
	}

	return dp[x];
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	// printf("%d\n", topDown(n));
	printf("%d\n", bottomUp(n));
}