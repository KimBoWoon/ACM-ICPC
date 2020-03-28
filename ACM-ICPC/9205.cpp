#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int t, n;
bool visited[102];
vector<int> graph[102];

int distance(pair<int, int>& x, pair<int, int>& y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

void dfs(int x) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    scanf("%d", &t);

    while (t--) {
        vector<pair<int, int>> v;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 102; i++) {
            graph[i].clear();
        }

        scanf("%d", &n);

        for (int i = 0; i < n + 2; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.push_back({ x, y });
        }

        // 맨하튼 거리를 통해서 1000안으로 이동할 수 있으면 양방향 그래프 연결
        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                if (distance(v[i], v[j]) <= 1000) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        dfs(0);

        if (visited[n + 1]) {
            printf("happy\n");
        } else {
            printf("sad\n");
        }
    }
}