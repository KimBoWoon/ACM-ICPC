#define LOCAL

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define INF 987654321
vector<pair<int, int> > v[10001], rv[10001];
// first는 거리, second는 다음 정점.
priority_queue<pair<int, int> > q, rq;
int dist[10001], rdist[10001];
int n, m, x, maxDist;

void dijkstra(vector<pair<int, int> > v[10001], int *dist) {
	dist[x] = 0;
	q.push(make_pair(0, x));

	while (!q.empty()) {
		pair<int, int> value = q.top();
		q.pop();

		int current = value.second;
		int cost = -value.first;

		// 현재 정점까지의 거리가 더 짧은 경우 무시.
		if (dist[current] < cost) {
			continue;
		}

		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].second;
			int nextCost = v[current][i].first + dist[current];

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				q.push(make_pair(-nextCost, next));
			}
		}
	}
}


int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(make_pair(cost, to));
		rv[to].push_back(make_pair(cost, from));
	}

	// 시작 정점부터 next 정점까지의 최단거리를 빠르게 참조 및 갱신하기 위한 배열.
	for (int i = 0; i < 10001; i++) {
		dist[i] = rdist[i] = INF;
	}

	dijkstra(v, dist);
	dijkstra(rv, rdist);

	/*for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (rdist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", rdist[i]);
		}
	}*/

	for (int i = 1; i <= n; i++) {
		maxDist = max(maxDist, dist[i] + rdist[i]);
	}

	printf("%d\n", maxDist);

	return 0;
}