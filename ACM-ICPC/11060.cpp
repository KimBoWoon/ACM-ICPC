#define LOCAL

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n, ans;
int map[1001], dp[1001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}

	fill(dp, dp + n, INT_MAX);

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		// 점프 할 수 있는 거리
		int jump = map[i];

		// 점프 할 수 있는 모든 거리를 체크
		for (int j = jump; j > 0; j--) {
			// 아직 방문 하지 않았으면
			if (dp[i] != INT_MAX) {
				// 만약 현재 가지고 있는 값과 이동 했을 때의 값을 비교하여
				// 더 작은 값을 넣는다
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
			}
		}
	}

	if (dp[n - 1] == INT_MAX) {
		printf("-1\n");
	}
	else {
		printf("%d\n", dp[n - 1]);
	}
}