#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;
int n, m, a, b;
int map[101][101], d[101];

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &m);

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		map[x][y] = map[y][x] = 1;
	}

	q.push(a);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[now][i] == 0 || d[i] != 0) {
				continue;
			}
			d[i] = d[now] + 1;
			q.push(i);
		}
	}

	printf("%d\n", d[b] == 0 ? -1 : d[b]);

	return 0;
}