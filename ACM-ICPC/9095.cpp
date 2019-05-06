#include <bits/stdc++.h>

int t, n;
int dp[101];

// 1, 2, 3을 더해서 n을 표현하는 방법의 가지수를 d[n]
// dp[x를 1로 만드는 경우의 수]
// dp[x를 2로 만드는 경우의 수]
// dp[x를 3로 만드는 경우의 수]
// 전부 더 하면 된다
int topDown(int x) {
	if (x == 0) {
		dp[x] = 1;
	}
	if (x == 1) {
		dp[x] = 1;
	}
	if (x == 2) {
		dp[x] = 2;
	}
	if (x >= 3) {
		dp[x] = topDown(x - 1) + topDown(x - 2) + topDown(x - 3);
	}

	return dp[x];
}

int bottomUp(int x) {
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[x];
}

int main() {
	scanf("%d", &t);

	while (t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		printf("%d\n", topDown(n));
		// printf("%d\n", bottomUp(n));
	}
}