#include <cstdio>
#include <queue>
using namespace std;

int n, m, cnt;
int visit[101];
int map[101][101];
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 101; i++) {
			if (map[cur][i] && !visit[i]) {
				visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		map[x][y] = map[y][x] = 1;
	}

	q.push(1);
	bfs();

	printf("%d\n", cnt - 1);
}