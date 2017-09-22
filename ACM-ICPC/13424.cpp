#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#pragma warning(disable:4996)

#define INF 987654321

int main(void) {
	int t;

	scanf("%d", &t);

	while (t--) {
		int V, E, k;
		int dist[101], ans[101] = { 0 };
		vector<pair<int, int> > v[101];

		scanf("%d %d", &V, &E);

		for (int i = 0; i < E; i++) {
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			v[from].push_back(make_pair(cost, to));
			v[to].push_back(make_pair(cost, from));
		}

		scanf("%d", &k);

		while (k--) {
			int start;
			// first는 거리, second는 다음 정점.
			priority_queue<pair<int, int> > q;

			scanf("%d", &start);

			// 시작 정점부터 next 정점까지의 최단거리를 빠르게 참조 및 갱신하기 위한 배열.
			for (int i = 0; i <= V; i++) {
				dist[i] = INF;
			}

			dist[start] = 0;
			q.push(make_pair(0, start));

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

			for (int i = 1; i <= V; i++) {
				if (dist[i] == INF) {
					continue;
				}
				else {
					ans[i] += dist[i];
				}
			}
		}

		int min = INF;
		int idx = 0;
		for (int i = 1; i <= V; i++) {
			if (ans[i] < min) {
				min = ans[i];
				idx = i;
			}
		}

		printf("%d\n", idx);
	}

	return 0;
}