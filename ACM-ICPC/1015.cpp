#include <cstdio>
using namespace std;

int n, a[51], b[51];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				b[j]++;
			}
			else {
				b[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}