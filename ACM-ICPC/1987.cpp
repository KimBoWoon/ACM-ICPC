#include <cstdio>
using namespace std;

int n, m, answer;
int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, alphabet[26];
char map[21][21];

void dfs(int x, int y, int count) {
	// 범위를 벗어나거나 이미 사용한 알파벳이면
	if (x < 0 || y < 0 || x >= n || y >= m || alphabet[map[x][y]]) {
		return;
	}

	answer = (answer > count) ? answer : count;

	alphabet[map[x][y]] = 1;
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i], count + 1);
	}
	alphabet[map[x][y]] = 0;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	// 시작 위치, 사용한 알파벳 개수
	dfs(0, 0, 1);
	printf("%d\n", answer);
}