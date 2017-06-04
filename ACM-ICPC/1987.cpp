#include <cstdio>
using namespace std;

int n, m, r;
int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, check[100];
char map[21][21];

void dfs(int x, int y, int z) {
	if (x < 0 || y < 0 || x >= n || y >= m || check[map[x][y]]) {
		return;
	}

	r = r > z ? r : z;

	check[map[x][y]] = 1;
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i], z + 1);
	}
	check[map[x][y]] = 0;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &map[i]);
	}

	dfs(0, 0, 1);
	printf("%d\n", r);
}