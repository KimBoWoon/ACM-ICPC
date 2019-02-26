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

void bfs() {
	while (!q.empty()) {
		int px = q.front().x, py = q.front().y, pz = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
            int nz = pz + dz[i];

			if (nx > -1 && nx < h && ny > -1 && ny < n && nz > -1 && nz < m) {
				if (visit[nx][ny][nz] == 0) {
					q.push({ nx, ny, nz });
					visit[nx][ny][nz] = visit[px][py][nz] + 1;
				}
			}
		}
	}
}

bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
			    if (visit[i][j][k] == 0) {
    				return false;
			    }
			    else {
				    ans = max(ans, visit[i][j][k]);
			    }
		    }
        }
	}

	return true;
}

int main() {
	scanf("%d %d %d", &m, &n, &h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &map[i][j][k]);
                visit[i][j][k] = map[i][j][k];
                if (map[i][j][k] == 1) {
                    q.push({ i, j, k });
                    visit[i][j][k] = 1;
                }
            }
		}
	}

	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < m; j++) {
    //         for (int k = 0; k < n; k++) {
    //             printf("%d ", map[i][j][k]);
    //         }
    //         printf("\n");
	// 	}
    //     printf("\n");
	// }

	bfs();

    for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                printf("%d ", visit[i][j][k]);
            }
            printf("\n");
		}
        printf("\n");
	}

	if (!check()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans - 1);
	}
}

// #include <stdio.h>
// #include <queue>
// using namespace std;
 
// int m, n, h, cnt;
// int tomato[100][100][100];
// int visit[100][100][100];
// int dir[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
 
// struct col {
//     int x, y, z;
// };
// queue<col> q;
 
// int bfs() {
//     int ans = 1;
//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; ++i) {
//             col c1 = q.front();
//             q.pop();
//             int x = c1.x, y = c1.y, z = c1.z;
 
//             if (visit[x][y][z])
//                 continue;
//             else
//                 visit[x][y][z] = 1;
 
//             for (int j = 0; j < 6; ++j) {
//                 int xx = x + dir[j][0];
//                 int yy = y + dir[j][1];
//                 int zz = z + dir[j][2];
 
//                 if (xx < 0 || xx >= h)
//                     continue;
//                 if (yy < 0 || yy >= n)
//                     continue;
//                 if (zz < 0 || zz >= m)
//                     continue;
//                 if (tomato[xx][yy][zz] == -1)
//                     continue;
 
//                 if (tomato[xx][yy][zz] == 0) {
//                     q.push({ xx,yy,zz });
//                     tomato[xx][yy][zz] = tomato[x][y][z] + 1;
//                     cnt--;
//                 }
                
//                 if (cnt == 0)
//                     return ans;
//             }
//         }
//         ans++;
//     }
//     return -1;
// }
 
// int main() {
//     scanf("%d %d %d", &m, &n, &h);
//     for (int i = 0; i < h; ++i) {
//         for (int j = 0; j < n; ++j) {
//             for (int k = 0; k < m; ++k) {
//                 scanf("%d", &tomato[i][j][k]);
//                 if (tomato[i][j][k] == 0)
//                     cnt++;
//                 else if (tomato[i][j][k] == 1)
//                     q.push({ i,j,k });
//             }
//         }
//     }

//     printf("%d\n", bfs());

//     for (int i = 0; i < h; i++) {
// 		for (int j = 0; j < n; j++) {
//             for (int k = 0; k < m; k++) {
//                 printf("%d ", tomato[i][j][k]);
//             }
//             printf("\n");
// 		}
//         printf("\n");
// 	}
 
//     return 0;
// }