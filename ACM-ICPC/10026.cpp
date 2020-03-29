#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int n, ans, ans2;
int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
char map[101][101], map2[101][101];
queue<point> q;

void bfs(char c) {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < n && nx > -1 && ny < n && ny > -1) {
				if (map[nx][ny] == c) {
					q.push({ nx, ny });
					map[nx][ny] = 'z'; // 상관없는 문자로 할당
				}
			}
		}
	}
}

void bfs2(char c) {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < n && nx > -1 && ny < n && ny > -1) {
				if (map2[nx][ny] == c) {
					q.push({ nx, ny });
					map2[nx][ny] = 'z'; // 상관없는 문자로 할당
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);

    // 평범한 사람이 볼 수 있는 색
	for (int i = 0; i < n; i++) {
		scanf("%s", &map[i]);
	}

    // 적록색약일 경우에 보이는 색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R' || map[i][j] == 'G') {
				map2[i][j] = 'R';
			}
			else {
				map2[i][j] = map[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 'z') {
				q.push({ i, j });
				bfs(map[i][j]);
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 'z') {
				q.push({ i, j });
				bfs2(map2[i][j]);
				ans2++;
			}
		}
	}

	printf("%d %d\n", ans, ans2);
}