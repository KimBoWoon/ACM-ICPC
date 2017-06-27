#include <cstdio>

#define MOD 15746

int n;
int dp[1000001];

int main() {
	scanf("%d", &n);

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	printf("%d\n", dp[n]);
}