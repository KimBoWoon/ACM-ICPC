#include <cstdio>
using namespace std;

int main() {
	int n, fac = 1;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		fac *= i;
	}

	printf("%d\n", fac);
}