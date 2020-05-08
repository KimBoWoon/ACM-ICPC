#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, answer;
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
				answer = max(answer, dp[i][j]);
			}
		}
	}

	printf("%d\n", answer * answer);
}

// 정사각형이 되려면 왼쪽 위, 위, 왼쪽이 모두 1이고 현재 자리에서도 1이여한다