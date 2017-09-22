#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int n, m, k, ans = 0, sum = 0;
		int home[100001] = { 0 };

		scanf("%d %d %d", &n, &m, &k);

		for (int i = 0; i < n; i++) {
			scanf("%d", &home[i]);
		}

		if (n == m) {
			for (int i = 0; i < n; i++) {
				sum += home[i];
			}

			if (sum < k) {
				ans++;
			}
		}
		else {
			for (int i = 0; i < m - 1; i++) {
				sum += home[i];
			}

			for (int i = m - 1; i < n + m - 1; i++) {
				sum += home[i % n];

				if (sum < k) {
					ans++;
				}

				sum -= home[(i - (m - 1))];
			}
		}

		printf("%d\n", ans);
	}
}