#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

int arr[51][51];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int testCase, row, col, n, cnt;
queue< pair<int, int> > q;

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x > row || y > col || !arr[x][y]) {
		return;
	}

	arr[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i]);
	}
}

void bfs(int x, int y) {
	arr[x][y] = 0;
	q.pop();
	for (int i = 0; i < 4; i++) {
		if (arr[x + dx[i]][y + dy[i]] == 1) {
			arr[x + dx[i]][y + dy[i]] = 0;
			q.push(make_pair(x + dx[i], y + dy[i]));
		}
	}
}

int main() {
	scanf("%d", &testCase);

	while (testCase--) {
		memset(arr, 0, 51 * 51);

		cnt = 0;

		scanf("%d %d %d", &row, &col, &n);

		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		/*for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j]) {
					cnt++;
					q.push(make_pair(i, j));
					while (q.size()) {
						bfs(q.front().first, q.front().second);
					}
				}
			}
		}*/

		printf("%d\n", cnt);
	}
}