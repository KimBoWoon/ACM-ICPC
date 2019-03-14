#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 110001

int n, k, m, answer;
int visit[MAX];
vector<vector<int> > v;
queue<int> q;

int bfs(int start) {
    q.push(start);
    visit[start] = 1;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < v[here].size(); i++) {
            if (visit[v[here][i]] == 0) {
                q.push(v[here][i]);
                visit[v[here][i]] = visit[here] + 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &m);

    v.resize(n + m + 1);

    // 하이퍼 튜브를 하나의 정점이라고 생각한다
    for (int i = n + 1; i < n + m + 1; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
            v[x].push_back(i);
        }
    }

    bfs(1);

    printf("%d\n", (visit[n] == 0) ? -1 : visit[n] / 2 + 1);
}