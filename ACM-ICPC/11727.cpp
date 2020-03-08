#include <bits/stdc++.h>

#define MOD 10007

typedef unsigned long long ULLONG;

int n;
ULLONG dp[1001];

ULLONG topDown(int x) {
	if (x == 0) {
		return dp[x] = 0;
	}
	if (x == 1) {
		return dp[x] = 1;
	}
	if (x == 2) {
		return dp[x] = 3;
	}

	if (dp[x] != -1) {
		return dp[x];
	}

	dp[x] = (topDown(x - 1) + topDown(x - 2) * 2) % MOD;

	return dp[x] % MOD;
}

ULLONG bottomUp(int x) {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= x; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
	}

	return dp[x] % MOD;
}

int main() {
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", topDown(n));
	// printf("%lld\n", bottomUp(n));

	return 0;
}

// 길이가 1 남고 1x2 타일 한 개로 채우는 경우 길이 n - 1의 타일을 채우는 경우
// 길이가 2 남고 2x1 타일 두 개로 채우는 경우 길이 n - 2의 타일을 채우는 경우
// 길이가 2 남고 2x2 타일 한 개로 채우는 경우 길이 n - 2의 타일을 채우는 경우
// dp[n - 1] + dp[n - 2] * 2