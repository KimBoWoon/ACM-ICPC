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

	// 플로이드 역으로 활용
	// 모든 경로로 갈 수 있다고 문제에 정의됨 -> map 배열에 각 정점에 대해 모든 간선 연결
	// 최단 경로가 존재하면 i->j로 가는 간선은 없애버린다. i->k->j가 존재함으로써 i->j가 존재할 필요가 없음.
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