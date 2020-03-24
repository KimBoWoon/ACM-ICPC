#include <cstdio>
#include <queue>
using namespace std;

int n, m, ans, cnt;
bool arr[501][501];
bool mark[1020];

void bfs(int v) {
	queue<int> q;

	q.push(v);
	mark[v] = true;

	while (!q.empty()) {
		int size = q.size();
		// 1번 부터 시작 1번이 상근이다
		while (size--) {
			int x = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (arr[x][i] && !mark[i]) { // arr[x][i]가 참이고 방문하지 않았다면 친구
					q.push(i);
					mark[i] = true;
					ans++;
				}
			}
		}
		// cnt가 2 이상이면 탐색을 2번 했다는 것 그것은 친구의 친구까지 탐색했다는 것을 의미
		if (++cnt > 1) {
			break;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	// 양방향 그래프 생성
	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		arr[x - 1][y - 1] = true;
		arr[y - 1][x - 1] = true;
	}

	bfs(0);

	printf("%d\n", ans);
}