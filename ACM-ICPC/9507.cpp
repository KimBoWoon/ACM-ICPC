#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

unsigned long long arr[70] = { 0 };

int main() {
	int t;

	scanf("%d", &t);

	for (int i = 0; i < 70; i++) {
		if (i < 2) {
			arr[i] = 1;
		}
		else if (i == 2) {
			arr[i] = 2;
		}
		else if (i == 3) {
			arr[i] = 4;
		}
		else if (i > 3) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
		}
	}

	while (t--) {
		int n;

		scanf("%d", &n);

		printf("%lld\n", arr[n]);
	}
}