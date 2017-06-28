#include <cstdio>

int main() {
	int t, n;

	scanf("%d", &t);

	while (t--) {
		int d[101] = { 0 };

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; i*j <= n; j++) {
				if (d[i*j]) {
					d[i*j] = !d[i*j];
				}
				else {
					d[i*j] = !d[i*j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			d[0] += d[i];
		}
		printf("%d\n", d[0]);
	}
}

int main() {
	int i, t, n;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (i = 1; i * i <= n; i++);

		printf("%d\n", i - 1);
	}
}