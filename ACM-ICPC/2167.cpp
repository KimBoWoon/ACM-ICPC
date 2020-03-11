#include <cstdio>
using namespace std;

int n, m, k;
int arr[301][301], dp[301][301];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}

	scanf("%d", &k);

	while (k--) {
		int i, j, x, y;

		scanf("%d %d %d %d", &i, &j, &x, &y);

		printf("%d\n", dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1]);
	}
}

// 부분합을 2차원으로 확장

// int main() {
// 	scanf("%d %d", &n, &m);

// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= m; j++) {
// 			scanf("%d", &arr[i][j]);
// 		}
// 	}

// 	scanf("%d", &k);

// 	while (k--) {
// 		int i, j, x, y, sum = 0;

// 		scanf("%d %d %d %d", &i, &j, &x, &y);

// 		for (int a = i; a <= x; a++) {
// 			for (int b = j; b <= y; b++) {
// 				sum += arr[a][b];
// 			}
// 		}

// 		printf("%d\n", sum);
// 	}

// 	return 0;
// }