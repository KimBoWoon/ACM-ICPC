#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

// struct comp { // pair은 first를 우선으로 비교하기 때문에 시간초과가 발생한다
// 	bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
// 		return x.second < y.second; // 그래서 second를 우선으로 비교한다
// 	}
// };

vector<pair<int, int> > v[20001];
// priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
priority_queue<pair<int, int> > pq;
int dist[20001];
int V, E, start;

// void dijkstra() {
// 	dist[start] = 0;
// 	pq.push({ start, 0 });

// 	while (!pq.empty()) {
// 		pair<int, int> value = pq.top();
// 		pq.pop();

// 		int current = value.first;
// 		int cost = -value.second;

// 		if (dist[current] < cost) {
// 			continue;
// 		}

// 		for (int i = 0; i < v[current].size(); i++) {
// 			int next = v[current][i].first;
// 			int nextCost = v[current][i].second + dist[current];

// 			if (dist[next] > nextCost) {
// 				dist[next] = nextCost;
// 				pq.push(make_pair(next, -nextCost));
// 			}
// 		}
// 	}
// }

void dijkstra() {
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		pair<int, int> value = pq.top();
		pq.pop();

		int current = value.second;
		int cost = -value.first;

		if (dist[current] < cost) {
			continue;
		}

		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].second;
			int nextCost = v[current][i].first + dist[current];

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &V, &E, &start);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		// v[from].push_back({ to, cost });
		v[from].push_back({ cost, to });
	}

	for (int i = 0; i < 20001; i++) {
		dist[i] = INF;
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}

	return 0;
}