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
		// 0잔 연속
		// n번째 포도주를 0번 마실 경우 n-1의 포도주는 마셔도 되고 안 마셔도 되고 그러니까 그냥 dp[n-1]의 값이 n번째 포도주를 0번 연속 마셨을 경우랑 같습니다.
		// dp[n] = dp[n - 1]
		dp[i] = dp[i - 1];

		// 1잔 연속
		// n번째 포도주를 1번 연속 마실 수 있는 경우가 되기 위해선 n-1 번째 포도주는 마시면 안됨
		// 마시면 n번째 포도주는 2번 연속 마시게 된다
		// 그 다음 n-2 번째 있는 포도주는 마셔도 되고 안마셔도 된다 이미 n-1번째 포도주를 안 마신 것으로도 n번째 포도주가 1번 연속 마실 수 있는 경우를 만족
		// dp[n] = dp[n-2]+p[n]
		if (dp[i] < dp[i - 2] + wine[i]) {
			dp[i] = dp[i - 2] + wine[i];
		}

		// 2잔 연속
		// 2번 연속이니 n-1 포도주는 마셔야 된다
		// n-2번째는 마시면 안됨
		// n번째 포도주가 2번 연속으로 마셨을 경우가 충족
		// 그 다음 n-3번째 포도주는 마셔도 되고 안마셔도 된다
		// dp[n]  = dp[n-3]+p[n-1]+p[n]
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

// https://limkydev.tistory.com/112