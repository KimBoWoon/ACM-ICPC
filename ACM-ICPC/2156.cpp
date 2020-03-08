#include <bits/stdc++.h>
using namespace std;

int n;
int wine[10001], dp[10001];

int topDown(int x) {
	if (x == 1) {
		dp[0] = wine[0];
		return dp[1] = wine[0] + wine[1];
	}

	if (dp[x] != 0) {
		return dp[x];
	}

	topDown(x - 1);

	dp[x] = dp[x - 1];
	dp[x] = max(dp[x], dp[x - 2] + wine[x]);
	dp[x] = max(dp[x], dp[x - 3] + wine[x] + wine[x - 1]);

	return dp[x - 1];
}

int bottomUp(int x) {
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];

	for (int i = 2; i < x; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + wine[i]) {
			dp[i] = dp[i - 2] + wine[i];
		}
		if (dp[i] < dp[i - 3] + wine[i] + wine[i - 1]) {
			dp[i] = dp[i - 3] + wine[i] + wine[i - 1];
		}
	}

	return dp[x - 1];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &wine[i]);
	}

	printf("%d\n", topDown(n));
	// printf("%d\n", bottomUp(n));

	return 0;
}

// 연속으로 세잔 이상 마실수 없다
// 1, 2, 3 까지 마실수 있다
// 1 3 마셨을 때와 1 2 3 마셨을 때 최값으로 갱신