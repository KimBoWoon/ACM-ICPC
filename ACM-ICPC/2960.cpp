#define LOCAL

#include <cstdio>

#define MAX 1000

int n, m;
int prime[1001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++) {
		prime[i] = i;
	}

	while (true) {
		int dn = 0;
		for (int i = 2; i <= n; i++) {
			if (prime[i] != -1) {
				dn = i;
				break;
			}
		}

		for (int i = dn; i <= n; i += dn) {
			if (prime[i] == -1) {
				continue;
			}
			prime[i] = -1;
			m--;
			if (m == 0) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
}