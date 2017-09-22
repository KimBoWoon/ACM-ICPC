#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

unsigned long long fibo[46];

int main() {
	int n;

	scanf("%d", &n);

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%lld\n", fibo[n]);

	return 0;
}