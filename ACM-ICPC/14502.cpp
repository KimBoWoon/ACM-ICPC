#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans, temp;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int map[8][8], factory[8][8];
vector<pair<int, int>> wall;

void bfs(int x, int y) {
	queue<pair<int, int> > q;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (factory[x][y] == 2) {
				q.push(make_pair(x, y));
			}
		}
	}

	//q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0 || x + dx[i] > n || y + dy[i] < 0 || y + dy[i] > m) {
				continue;
			}
			if (factory[x + dx[i]][y + dy[i]] == 0) {
				q.push(make_pair(x + dx[i], y + dy[i]));
				factory[x + dx[i]][y + dy[i]] = 2;
			}
		}
	}
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int newX = dx[i] + x;
		int newY = dy[i] + y;

		if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
			if (factory[newX][newY] == 0) {
				factory[newX][newY] = 2;
				dfs(newX, newY);
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			factory[i][j] = map[i][j];
			if (map[i][j] == 0) {
				wall.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < wall.size() - 2; i++) {
		for (int j = i + 1; j < wall.size() - 1; j++) {
			for (int k = j + 1; k < wall.size(); k++) {
				pair<int, int> wall1 = wall[i];
				pair<int, int> wall2 = wall[j];
				pair<int, int> wall3 = wall[k];

				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						factory[x][y] = map[x][y];
					}
				}

				factory[wall1.first][wall1.second] = 1;
				factory[wall2.first][wall2.second] = 1;
				factory[wall3.first][wall3.second] = 1;

				/*for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						printf("%d ", factory[x][y]);
					}
					printf("\n");
				}
				printf("\n");*/

				//for (int x = 0; x < n; x++) {
				//	for (int y = 0; y < m; y++) {
				//		if (factory[x][y] == 2) {
				//			bfs(x, y);
				//			//dfs(x, y);
				//		}
				//	}
				//}

				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						bfs(x, y);
					}
				}

				/*for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						printf("%d ", factory[x][y]);
					}
					printf("\n");
				}
				printf("\n");*/

				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						if (factory[x][y] == 0) {
							temp++;
						}
					}
				}

				ans = max(ans, temp);
				temp = 0;
			}
		}
	}

	printf("%d\n", ans);
}