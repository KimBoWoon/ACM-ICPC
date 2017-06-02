#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int map[301][301];
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int testCase, n, ans;
queue<point> q;
point source, destination;

void bfs() {
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx > -1 && nx < n && ny > -1 && ny < n) {
				q.push({ nx, ny });
				map[nx][ny] = map[px][py] + 1;

				if (nx == destination.x && ny == destination.y) {
					return;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &testCase);

	while (testCase--) {
		ans = 0;

		scanf("%d", &n);
		scanf("%d %d", &source.x, &source.y);
		scanf("%d %d", &destination.x, &destination.y);

		q.push(source);
		bfs();

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/

		printf("%d\n", ans);
	}
}