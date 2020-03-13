#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, x;
int dp[10001];

int main() {
	scanf("%d %d", &n, &k);

	// 정답이 되지 못하는 값으로 초기화
	for (int i = 1; i < 10001; i++) {
		dp[i] = 10001;
	}

	// 동전의 수 만큼 반복
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);

		// x로 시작 => x원 이하는 x원으로 만들 수 없기 때문
		// k원 까지 반복
		for (int j = x; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - x] + 1);
		}
	}

	printf("%d\n", (dp[k] == 10001) ? -1 : dp[k]);
}