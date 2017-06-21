#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int m, n, k;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int map[101][101];
queue<point> q;
vector<int> v;

void bfs() {
	int ans = 1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x, ny = dy[i] + y;

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = -1;
					ans++;
					q.push({ nx, ny });
				}
			}
		}
	}

	v.push_back(ans);
}

int main() {
	scanf("%d %d %d", &m, &n, &k);

	for (int z = 0; z < k; z++) {
		int x1, x2, y1, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				map[i][j] = -1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = -1;
				q.push({ i, j });
				bfs();
			}
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}