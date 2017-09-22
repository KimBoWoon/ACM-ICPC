#include <cstdio>
#include <queue>
using namespace std;

int n, k, visit[100001];
queue<int> q;

int bfs() {
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		if (p == k) {
			return visit[p] - 1;
		}

		if (p - 1 >= 0 && visit[p - 1] == 0) {
			visit[p - 1] = visit[p] + 1;
			q.push(p - 1);
		}

		if (p + 1 <= 100000 && visit[p + 1] == 0) {
			visit[p + 1] = visit[p] + 1;
			q.push(p + 1);
		}

		if (2 * p <= 100000 && visit[2 * p] == 0) {
			visit[2 * p] = visit[p] + 1;
			q.push(2 * p);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs());
}