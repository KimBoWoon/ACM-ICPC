#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

int n;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int arr[101][101];
bool visited[101][101];
vector<int> v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            v.push_back(arr[i][j]);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int answer = 987654321, low = 0, high = 0;

    while (low < v.size()) {
        queue<point> q;

        memset(visited, false, sizeof(visited));

        if (arr[0][0] >= v[low] && arr[0][0] <= v[high]) {
            visited[0][0] = true;
            q.push({ 0, 0 });
        }

        while (!q.empty()) {
            point p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];

                if ((nx > -1 && nx < n && ny > -1 && ny < n) && !visited[nx][ny]) {
                    if (arr[nx][ny] >= v[low] && arr[nx][ny] <= v[high]) {
                        visited[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
        }

        if (visited[n - 1][n - 1]) {
            answer = min(answer, v[high] - v[low]);
            low++;
        } else if (high < v.size() - 1) {
            high++;
        } else {
            break;
        }
    }

    printf("%d\n", answer);
}