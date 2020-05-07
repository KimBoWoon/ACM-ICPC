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

// 0 1 (안 만드는 경우)
// 1 1 1
// 2 00 11 2
// 3 001 100 111 3
// 4 0000 0011 1100 1001 1111 5
// 이후로는 피보나치 수열