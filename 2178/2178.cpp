#include <cstdio>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

#define SIZE 101

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int maze[SIZE][SIZE];
int n, m;

void BFS(int x, int y) {
	queue<pair<int, int> > q;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] <= 0 || x + dx[i] > n || y + dy[i] <= 0 || y + dy[i] > m) {
				continue;
			}
			if (maze[x + dx[i]][y + dy[i]] == 1) {
				q.push(make_pair(x + dx[i], y + dy[i]));
				maze[x + dx[i]][y + dy[i]] = maze[x][y] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	BFS(1, 1);

	printf("%d\n", maze[n][m]);
}