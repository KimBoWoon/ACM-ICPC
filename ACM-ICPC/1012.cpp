#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

int arr[51][51];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int testCase, row, col, n, cnt;

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x > row || y > col || !arr[x][y]) { // 범위안에 없거나 배추가 있는곳이 아니면 리턴
		return;
	}

	arr[x][y] = 0; // 확인하고 배추가 있던 곳을 0으로 체크

	for (int i = 0; i < 4; i++) { // 다음 탐색지 체크
		dfs(x + dx[i], y + dy[i]);
	}
}

void bfs(int x, int y) {
	queue< pair<int, int> > q;
	q.push({ x, y });
	arr[x][y] = 0;
	
	while (!q.empty()) {
		pair<int, int> value = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = value.first + dx[i], ny = value.second + dy[i];

			if (nx > -1 && nx < row && ny > -1 && ny < col) { // 다음 좌표가 배추밭 안에 있다면
				if (arr[value.first + dx[i]][value.second + dy[i]] == 1) {
					arr[value.first + dx[i]][value.second + dy[i]] = 0; // 확인하고 배추가 있던 곳을 0으로 체크
					q.push(make_pair(value.first + dx[i], value.second + dy[i])); // 큐에 다음 탐색지 저장
				}
			}
		}
	}
}

int main() {
	scanf("%d", &testCase);

	while (testCase--) {
		memset(arr, 0, sizeof(arr));

		cnt = 0;

		scanf("%d %d %d", &row, &col, &n);

		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		// for (int i = 0; i < row; i++) {
		// 	for (int j = 0; j < col; j++) {
		// 		if (arr[i][j]) { // 배추가 있는 곳이면 dfs 탐색 시작
		// 			cnt++;
		// 			dfs(i, j);
		// 		}
		// 	}
		// }

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j]) { // 배추가 있는 곳이면 bfs 탐색 시작
					cnt++;
					bfs(i, j);
				}
			}
		}

		printf("%d\n", cnt);
	}
}