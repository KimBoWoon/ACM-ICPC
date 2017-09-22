#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int n, sum;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
	}

	printf("%d\n", sum - n + 1);

	return 0;
}