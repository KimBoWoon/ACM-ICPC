#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
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

			if (nx > -1 && nx < n && ny > -1 && ny < n && !map[nx][ny]) {
				q.push({ nx, ny });
				map[nx][ny] = map[px][py] + 1;
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

		memset(map, 0, sizeof(int) * 301 * 301);
		map[source.x][source.y] = 1;
		q.push(source);
		bfs();

		printf("%d\n", map[destination.x][destination.y] - 1);
	}
}