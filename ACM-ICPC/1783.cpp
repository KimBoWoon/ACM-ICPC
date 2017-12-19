#include <cstdio>

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	if (n == 1) {
		printf("1\n");
	}
	else if (n == 2) {
		if (m <= 6) {
			printf("%d\n", (m + 1) / 2);
		}
		else {
			printf("4\n");
		}
	}
	else {
		if (m <= 4) {
			printf("%d\n", m);
		}
		else if (m == 5 || m == 6) {
			printf("4\n");
		}
		else {
			printf("%d\n", m - 2);
		}
	}
	return 0;
}