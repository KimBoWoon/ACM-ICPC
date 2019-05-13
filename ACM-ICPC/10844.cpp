#include <bits/stdc++.h>

#define MOD 1000000000

typedef unsigned long long ULLONG;

int n;
ULLONG sum;
ULLONG dp[101][11];

ULLONG topDown(int x, int y) {
	if (x == 1) {
		return (y == 0) ? 0 : 1;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	if (y == 0) {
		return dp[x][y] = topDown(x - 1, 1) % MOD;
	} else if (y == 9) {
		return dp[x][y] = topDown(x - 1, 8) % MOD;
	} else {
		return dp[x][y] = (topDown(x - 1, y - 1) + topDown(x - 1, y + 1)) % MOD;
	}
}

void bottomUp(int x) {
	// for (int i = 1; i < x; i++) {
	// 	for (int j = 1; j <= 10; j++) {
	// 		dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
	// 	}
	// }
	for (int i = 2; i <= x; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % MOD;
			} else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % MOD;
			} else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 10; i++) {
		sum = (sum + topDown(n, i)) % MOD;
	}
	// for (int i = 1; i < 10; i++) {
	// 	dp[1][i] = 1;
	// }
	// bottomUp(n);
	// for (int i = 0; i < 10; i++) {
	// 	sum = (sum + dp[n][i]) % MOD;
	// }

	printf("%lld\n", sum % MOD);

	return 0;
}