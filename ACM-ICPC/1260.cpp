#include <iostream>
#include <queue>
#include <memory>
#include <cstring>

using namespace std;

int n, m, v;
int arr[1020][1020];
bool mark[1020];

void dfs(int v) {
	cout << v << " ";
	mark[v] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] && !mark[i])
			dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;

	q.push(v);
	mark[v] = true;
	int x;
	while (!q.empty()) {
		x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[x][i] && !mark[i]) {
				q.push(i);
				mark[i] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}

	dfs(v);
	cout << endl;
	memset(mark, false, 1020);
	bfs(v);
	cout << endl;

	return 0;
}