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