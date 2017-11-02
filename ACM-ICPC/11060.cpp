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
		// ���� �� �� �ִ� �Ÿ�
		int jump = map[i];

		// ���� �� �� �ִ� ��� �Ÿ��� üũ
		for (int j = jump; j > 0; j--) {
			// ���� �湮 ���� �ʾ�����
			if (dp[i] != INT_MAX) {
				// ���� ���� ������ �ִ� ���� �̵� ���� ���� ���� ���Ͽ�
				// �� ���� ���� �ִ´�
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