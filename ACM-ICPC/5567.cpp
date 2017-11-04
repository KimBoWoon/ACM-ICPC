#define LOCAL

#include <cstdio>
#include <queue>
using namespace std;

int n, m, ans, cnt;
bool arr[501][501];
bool mark[1020];
int mark2[1020];

void bfs(int v) {
	queue<int> q;

	q.push(v);
	mark[v] = true;
	int x;
	while (!q.empty()) {
		int size = q.size();
		// ���� ������ ���� �ݺ���
		while (size--) {
			x = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (arr[x][i] && !mark[i]) {
					q.push(i);
					mark[i] = true;
					ans++;
				}
			}
		}
		// ���̰� 2�̸� ģ���� ģ������ �˻� �Ϸ�
		if (++cnt > 1) {
			break;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &m);

	// ������� �����
	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		arr[x - 1][y - 1] = true;
		arr[y - 1][x - 1] = true;
	}

	// bfs Ž��
	bfs(0);

	printf("%d\n", ans);
}