#include <cstdio>
#include <cstring>
using namespace std;

int n;
int map[101][101];
int mark[101];
int result[101][101];

void dfs(int v) {
	for (int i = 0; i < n; i++) {
		if (map[v][i] && !mark[i]) {
			mark[i] = 1; // 방문 했음을 표기
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		memset(mark, 0, sizeof(mark)); // 방문을 표시하기 위해 초기화

		dfs(i);

		for (int j = 0; j < n; j++) {
			result[i][j] = mark[j]; // 방문했던 곳으로 만든다
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}