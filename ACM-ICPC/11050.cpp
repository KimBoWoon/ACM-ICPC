#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int n, k;

int fact(int m) {
	int a = 1;

	for (int i = 1; i <= m; i++) {
		a *= i;
	}

	return a;
}

int main() {
	int a;

	scanf("%d %d", &n, &k);

	printf("%d\n", fact(n) / (fact(k) * fact(n - k)));
}