#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int w, h;
int map[51][51], visited[51][51];
int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[9] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void dfs(int i, int j, int ans) {
	visited[i][j] = ans;

	for (int t = 0; t < 9; t++) {
		int tx = j + dx[t];
		int ty = i + dy[t];
		if (1 <= tx && tx <= w && 1 <= ty && ty <= h) {
			if (map[ty][tx] == 1 && visited[ty][tx] == 0) {
				dfs(ty, tx, ans);
			}
		}
	}
}

int main() {
	while (true) {
		int ans = 0;

		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) {
			break;
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &map[i][j]);
				visited[i][j] = 0;
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					dfs(i, j, ++ans);
				}
			}
		}
		printf("%d\n", ans);
	}
}