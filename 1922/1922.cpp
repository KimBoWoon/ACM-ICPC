#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

typedef struct edge {
	int start, end, weight;
} Edge;

int up[500000];
int weight[500000];
int n, m, x, y, t;
vector<Edge> edge, selectEdge;

bool asc(const Edge &x, const Edge &y) {
	return x.weight < y.weight;
}

int SimpleFind(const int i) {
	int root = i;

	while (up[root] > 0) {
		root = up[root];
	}

	return root;
}

void Union(const int i, const int j) {
	int rooti = SimpleFind(i);
	int rootj = SimpleFind(j);

	if (weight[rooti] > weight[rootj]) {
		up[rootj] = rooti;
		weight[rooti] = weight[rooti] + weight[rootj];
		weight[rootj] = 0;
	}
	else if (weight[rooti] < weight[rootj]) {
		up[rooti] = rootj;
		weight[rootj] = weight[rooti] + weight[rootj];
		weight[rooti] = 0;
	}
	else if (weight[rooti] == weight[rootj]) {
		if (rooti > rootj) {
			up[rootj] = rooti;
			weight[rooti] = weight[rooti] + weight[rootj];
			weight[rootj] = 0;
		}
		else {
			up[rooti] = rootj;
			weight[rootj] = weight[rooti] + weight[rootj];
			weight[rooti] = 0;
		}
	}
}

void Kruskal() {
	int edgeCnt = 0;

	while (selectEdge.size() < n && edge.size() > edgeCnt) {
		int x = edge[edgeCnt].start, y = edge[edgeCnt].end;
		int p = SimpleFind(x);
		int q = SimpleFind(y);

		if (q != p) {
			Union(q, p);
			selectEdge.push_back({ edge[edgeCnt].start, edge[edgeCnt].end, edge[edgeCnt].weight });
		}
		edgeCnt++;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &t);
		edge.push_back({ x, y, t });
	}

	sort(edge.begin(), edge.end(), asc);

	Kruskal();

	int cost = 0;
	for (int i = 0; i < selectEdge.size(); i++) {
		cost += selectEdge[i].weight;
	}

	printf("%d\n", cost);

	return 0;
}