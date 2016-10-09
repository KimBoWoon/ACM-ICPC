#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int arr[51][51];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int testCase, row, col, n, cnt;

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x > row || y > col || !arr[x][y]) {
		return;
	}

	arr[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i]);
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

		printf("%d\n", cnt);
	}
}