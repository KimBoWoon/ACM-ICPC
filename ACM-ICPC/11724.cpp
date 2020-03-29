#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point {
    int x, y;
} point;

int n, m, x, y, ans;
int map[1001][1001];
bool mark[1001];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    mark[v] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if(!mark[i] && map[x][i]){
                bfs(i);
            }
        }
    }
}

void dfs(int v) {
    mark[v] = true;

    for (int i = 1; i <= n; i++) {
        if(!mark[i] && map[v][i]){
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            ans++;
            dfs(i);
        }
    }

    printf("%d\n", ans);
}

// 그래프의 개수를 세는 문제
// 모든 정점에서 탐색을 하면된다