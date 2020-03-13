#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001], dp[1001][1001];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	// 초기값
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 갈 수 있는 모든 경로에서 최댓값을 구한다
			dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	printf("%d\n", dp[n][m]);
}