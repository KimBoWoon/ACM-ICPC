#include <cstdio>

typedef unsigned long long ULLONG;

ULLONG sum;
int n, m, idx, max;
int map[1001][1001], check[1001][1001];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < map[i][j]) {
				max = map[i][j];
				idx = j;
			}
		}
		max = -1;
		check[i][idx] = 1;
	}

	max = -1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (max < map[j][i]) {
				max = map[j][i];
				idx = j;
			}
		}
		max = -1;
		check[idx][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] != 1) {
				sum += map[i][j];
			}
		}
	}

	printf("%lld\n", sum);
}