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
			mark[i] = 1;
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
		memset(mark, 0, 101);
		dfs(i);
		for (int j = 0; j < n; j++) {
			result[i][j] = mark[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}