#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[1001][1001], dp[1001][1001];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				ans = (ans > dp[i][j]) ? ans : dp[i][j];
			}
		}
	}

	printf("%d\n", ans * ans);
}