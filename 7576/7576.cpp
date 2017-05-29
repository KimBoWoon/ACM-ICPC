#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int n, m, ans;
int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
int map[1001][1001], visit[1001][1001];
queue<point> q;

void bfs() {
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx > 0 && nx < n && ny > 0 && ny < m) {
				if (map[ny][nx] == 0) {
					q.push({ ny, nx });
					visit[ny][nx] = 1;

				}
			}
		}
		ans++;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push({ j, i });
				visit[i][j] = 1;
				bfs();
			}
		}
	}

	printf("%d\n", ans);
}