#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

char arr[51][51];
int n, house;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int altitude[51][51];
bool visited[51][51];
vector<int> v;
point start;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);

        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'P') {
                start = { i , j };
            }
            if (arr[i][j] == 'K') {
                house++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &altitude[i][j]);
            v.push_back(altitude[i][j]);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int answer = 987654321, low = 0, high = 0;

    while (low < v.size()) {
        memset(visited, false, sizeof(visited));

        queue<point> q;
        int fatigue = altitude[start.x][start.y];

        if (fatigue >= v[low] && fatigue <= v[high]) {
            visited[start.x][start.y] = true;
            q.push({ start.x, start.y });
        }

        int houseCnt = 0;

        while (!q.empty()) {
            point p = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];

                if ((nx >= 0 && nx < n && ny >= 0 && ny < n) && !visited[nx][ny]) {
                    int temp = altitude[nx][ny];

                    if (temp >= v[low] && temp <= v[high]) {
                        visited[nx][ny] = true;
                        q.push({ nx, ny });

                        if (arr[nx][ny] == 'K') {
                            houseCnt++;
                        }
                    }
                }
            }
        }

        if (house == houseCnt) {
            answer = min(answer, v[high] - v[low]);
            low++;
        } else if (high + 1 < v.size()) {
            high++;
        } else {
            break;
        }
    }

    printf("%d\n", answer);
}