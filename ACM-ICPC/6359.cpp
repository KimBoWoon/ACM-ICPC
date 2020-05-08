#include <cstdio>

int t, n;
int dp[101];

// int main() {
// 	scanf("%d", &t);

// 	while (t--) {
// 		scanf("%d", &n);

// 		for (int i = 1; i <= n; i++) {
// 			for (int j = 1; i * j <= n; j++) {
// 				if (dp[i * j]) { // 열려있다면 닫아주고
// 					dp[i * j] = !dp[i * j];
// 				} else { // 닫혀있다면 열어주고
// 					dp[i * j] = !dp[i * j];
// 				}
// 			}
// 		}

// 		for (int i = 1; i <= n; i++) { // dp[0]은 사용하지 않는 변수이기 때문에 열려있는 방의 합을 구한다
// 			dp[0] += dp[i];
// 		}

// 		printf("%d\n", dp[0]);
// 	}
// }

int main() {
	scanf("%d", &t);

	while (t--) {
		int i = 1;

		scanf("%d", &n);

		while (i * i <= n) { // 진행하다 보면 i * i만 열려있다는 사실을 알수있게된다
			i++;
		}

		printf("%d\n", i - 1);
	}
}