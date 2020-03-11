#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

#define MOD 10007

int n, sum;
int arr[1001][10];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--) {
				arr[i][j] += (arr[i - 1][k]) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += (arr[n][i]) % MOD;
	}

	printf("%d\n", sum % MOD);
}

// dp[n번째 자리 수][해당하는 숫자]
// _ _ 7 일 경우 두 번째 자리에는 0 ~ 7 까지만 올 수 있다
// 이러한 경우를 생각하면 반복문 세개로 해결할 수 있다
// 1. 2부터 n까지(수의 길이를 의미)
// 2. 0 ~ 9까지(해당하는 자리에 들어 갈 수 있는 숫자를 의미)
// 3. 0 ~ j까지(i - 1번째 자리에 들어갈 수 있는 숫자를 의미)