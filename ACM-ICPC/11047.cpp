#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int coin[11];
int n, k, ans;

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}

	// 가장 큰 금액 부터 바꿔주면 최소 개수를 구할 수 있다.
	for (int i = n; i; i--) {
		if (coin[i] <= k) {
			k -= coin[i++];
			ans++;
		}
	}

	printf("%d\n", ans);
}