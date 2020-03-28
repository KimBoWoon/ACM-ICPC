#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
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

bool bfs(vector<pair<int, int>>& v, int x) {
    queue<pair<int, int>> q;
    visited[x] = true;
    q.push(v[x]);

    while (!q.empty()) {
        pair<int, int> value = q.front();
        q.pop();

        if (distance(v[v.size() - 1], value) <= 1000) { // 목적지까지 도달할 수 있는지 체크
            return true;
        }

        for (int i = 1; i <= n; i++) {
            if (distance(v[i], value) <= 1000 && !visited[i]) { // 아직 방문하지 않았고 맥주가게에 갈수 있는지 체크
                q.push(v[i]);
                visited[i] = true;
            }
        }
    }

    return false;
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

        // dfs(0);

        if (bfs(v, 0)) {
            printf("happy\n");
        } else {
            printf("sad\n");
        }

        // if (visited[n + 1]) {
        //     printf("happy\n");
        // } else {
        //     printf("sad\n");
        // }
    }
}