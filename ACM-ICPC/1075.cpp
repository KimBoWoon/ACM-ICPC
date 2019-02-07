#include <cstdio>

int n, f;

int main() {
	scanf("%d %d", &n, &f);

	n = n - n % 100;

	for (int i = 0; i < 99; i++) {
		if ((n + i) % f == 0) {
			(i < 10) ? printf("0%d\n", i) : printf("%d\n", i);
			break;
		}
	}
}