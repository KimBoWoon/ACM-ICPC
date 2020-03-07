#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

int n, minValue, maxValue;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int arr[101][101];
bool visited[101][101];
vector<int> v;

bool bfs(int mid) {
    for (int value = minValue; value <= maxValue - mid; value++) {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] < value) {
                    visited[i][j] = true;
                } else if (arr[i][j] >= value && arr[i][j] <= value + mid) {
                    visited[i][j] = false;
                } else {
                    visited[i][j] = true;
                }
            }
        }

        if (visited[0][0]) {
            continue;
        }

        queue<point> q;
        q.push({ 0, 0 });
        visited[0][0] = true;

        while (!q.empty()) {
            point p = q.front();
            q.pop();

            if (p.x == n - 1 && p.y == n - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];

                if ((nx > -1 && nx < n && ny > -1 && ny < n) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);

            maxValue = max(maxValue, arr[i][j]);
            minValue = min(minValue, arr[i][j]);
        }
    }

    int start = 0, end = maxValue - minValue;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (bfs(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    printf("%d\n", start);
}

// int main() {
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &arr[i][j]);
//             v.push_back(arr[i][j]);
//         }
//     }

//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());

//     int answer = 987654321, low = 0, high = 0;

//     while (low < v.size()) {
//         queue<point> q;

//         memset(visited, false, sizeof(visited));

//         if (arr[0][0] >= v[low] && arr[0][0] <= v[high]) {
//             visited[0][0] = true;
//             q.push({ 0, 0 });
//         }

//         while (!q.empty()) {
//             point p = q.front();
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int nx = p.x + dx[i], ny = p.y + dy[i];

//                 if ((nx > -1 && nx < n && ny > -1 && ny < n) && !visited[nx][ny]) {
//                     if (arr[nx][ny] >= v[low] && arr[nx][ny] <= v[high]) {
//                         visited[nx][ny] = true;
//                         q.push({ nx, ny });
//                     }
//                 }
//             }
//         }

//         if (visited[n - 1][n - 1]) {
//             answer = min(answer, v[high] - v[low]);
//             low++;
//         } else if (high < v.size() - 1) {
//             high++;
//         } else {
//             break;
//         }
//     }

//     printf("%d\n", answer);
// }