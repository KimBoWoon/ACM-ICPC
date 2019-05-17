#include <bits/stdc++.h>

typedef unsigned long long ULLONG;

int t, left, right;
ULLONG dp[31][31];

ULLONG topDown(int l, int r) {
	if (dp[l][r] != 0) {
		return dp[l][r];
	}
	if (l == r || r == 0) {
		return 1;
	} else if (l < r) {
		return 0;
	} else {
		return dp[l][r] = topDown(l - 1, r) + topDown(l - 1, r - 1);
	}
}

void bottomUp(int l, int r) {
	for (int i = 0; i < l; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < r; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i < l; i++) {
		for (int j = 1; j < r; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

int main() {
	memset(dp, 0, sizeof(dp));
	topDown(31, 31);
	// bottomUp(31, 31);
	
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &left, &right);
		printf("%lld\n", topDown(right, left));
		// printf("%lld\n", dp[right][left]);
	}
	return 0;
}