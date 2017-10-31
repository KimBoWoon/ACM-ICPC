#define LOCAL

#include <cstdio>

#define MAX 41

int n, m, ans = 1, temp;
int dp[50] = { 1, 1 };

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &m);

	for (int i = 2; i <= MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		ans *= dp[x - temp - 1];
		temp = x;
	}

	printf("%d\n", ans * dp[n - temp]);
}