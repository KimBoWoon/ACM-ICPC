#include <bits/stdc++.h>

#define MOD 10007

int n;
int dp[1001];

// 마지막에 올 수 있는 도형은
// 2x1 2개, 1x2 1개 이므로
// dp[n - 1] + dp[n - 2]가 된다
int topDown(int x) {
	if (x == 0) {
		return dp[0] = 0;
	}
	if (x == 1) {
		return dp[1] = 1;
	}
	if (x == 2) {
		return dp[2] = 2;
	}

	if (dp[x] > 0) {
		return dp[x];
	}

	return dp[x] = (topDown(x - 1) + topDown(x - 2)) % MOD;
}

int bottomUp(int x) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= x; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	return dp[x] % MOD;
}

int main() {
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	printf("%d\n", topDown(n));
	// printf("%d\n", bottomUp(n));
}