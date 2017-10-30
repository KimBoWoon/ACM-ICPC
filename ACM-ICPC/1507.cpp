#define LOCAL

#include <cstdio>

#pragma warning(disable: 4996)

int n, ans;
int dist[21][21], map[21][21], cost[21][21];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			dist[i][j] = map[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k) {
					continue;
				}
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					printf("-1\n");
					return 0;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					map[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != 0 && !cost[i][j]) {
				ans += dist[i][j];

				cost[i][j] = true;
				cost[j][i] = true;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}