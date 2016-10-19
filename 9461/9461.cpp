#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

unsigned long long arr[101];

int main() {
	int t;

	scanf("%d", &t);

	arr[0] = arr[1] = arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	while (t--) {
		int n;

		scanf("%d", &n);

		printf("%lld\n", arr[n - 1]);
	}

	return 0;
}