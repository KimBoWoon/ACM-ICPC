#include <bits/stdc++.h>
using namespace std;

int n;
int card[10001], dp[10001];

int topDown(int x) {
	if (x == 0) {
		return 0;
	}

	if (dp[x] != -1) {
		return dp[x];
	}

	for (int i = 1; i <= x; i++) {
		dp[x] = max(dp[x], topDown(x - i) + card[i]);
	}

	return dp[x];
}

int bottomUp(int x) {
	dp[1] = card[1];
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	return dp[x];
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}

	// memset(dp, -1, sizeof(dp));
	// printf("%d\n", topDown(n));
	printf("%d\n", bottomUp(n));

	return 0;
}