#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x, y, z;
} point;

int n, m, h, ans;
int dx[] = { 0, 1, 0, -1, 0, 0 }, dy[] = { 1, 0, -1, 0, 0, 0 }, dz[] = { 0, 0, 0, 0, 1, -1 };
int map[101][101][101], visit[101][101][101];
queue<point> q;

// void printMap() {
// 	for (int i = 0; i < h; i++) {
// 		for (int j = 0; j < m; j++) {
//             for (int k = 0; k < n; k++) {
//                 printf("%d ", map[i][j][k]);
//             }
//             printf("\n");
// 		}
//         printf("\n");
// 	}
// }

void bfs() {
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y, pz = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			int nz = pz + dz[i];

			if (nx > -1 && nx < h && ny > -1 && ny < m && nz > -1 && nz < n) {
				if (map[nx][ny][nz] == 0) {
					q.push({ nx, ny, nz });
					map[nx][ny][nz] = map[px][py][pz] + 1;
				}
			}
		}
	}
}

bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
			    if (map[i][j][k] == 0) {
    				return false;
			    }
			    else {
				    ans = max(ans, map[i][j][k]);
			    }
		    }
        }
	}

	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &map[i][j][k]);
                if (map[i][j][k] == 1) {
                    q.push({ i, j, k });
                }
            }
		}
	}

	bfs();

	if (!check()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans - 1);
	}
}