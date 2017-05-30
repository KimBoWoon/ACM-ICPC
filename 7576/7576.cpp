#include <cstdio>
#include <queue>
#include <algorithm>
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

			if (nx > -1 && nx < m && ny > -1 && ny < n) {
				if (visit[nx][ny] == 0) {
					q.push({ nx, ny });
					visit[nx][ny] = visit[px][py] + 1;
				}
			}
		}
	}
}

bool check() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				return false;
			}
			else {
				ans = max(ans, visit[i][j]);
			}
		}
	}

	return true;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = map[i][j];
			if (map[i][j] == 1) {
				q.push({ i, j });
				visit[i][j] = 1;
			}
		}
	}

	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push({ i, j });
				visit[i][j] = 1;
				bfs();
			}
		}
	}*/

	bfs();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}

	if (!check()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans - 1);
	}
}