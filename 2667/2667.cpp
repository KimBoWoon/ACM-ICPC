#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int map[26][26], visit[26][26];
int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
int n, cnt, homeCnt;
queue<point> q;

void bfs() {
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx > -1 && nx < n && ny > -1 && ny < n) {
				if (map[nx][ny] == 1) {
					q.push({ nx, ny });
					map[nx][ny] = 0; 
					visit[nx][ny] = visit[px][py] + 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			q.push({ i, j });
			visit[i][j] = 1;
			bfs();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
}