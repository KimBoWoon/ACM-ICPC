#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef struct Point {
    int x, y;
} point;

int testCase, n, m, a, b;
bool visited[1001];

bool comp(const point &x, const point &y) {
    if (!(x.y == y.y)) {
        return x.y < y.y;
    }
    return x.x < y.x;
}

int main() {
    scanf("%d", &testCase);

    while (testCase--) {
        int answer = 0;
        vector<point> v;

        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);

            v.push_back({ a, b });
        }

        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < m; i++) {
            for (int j = v[i].x; j <= v[i].y; j++) {
                if (!visited[j]) {
                    visited[j] = true;
                    answer++;
                    break;
                }
            }
        }

        printf("%d\n", answer);
        memset(visited, false, sizeof(visited));
    }
}