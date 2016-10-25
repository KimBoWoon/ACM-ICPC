#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

#define MOD 1000000000

unsigned long long arr[101][11];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= 10; i++) {
		arr[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 10; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % MOD;
		}
	}

	unsigned long long sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum = (sum + arr[n - 1][i]) % MOD;
	}

	printf("%lld\n", sum % MOD);

	return 0;
}