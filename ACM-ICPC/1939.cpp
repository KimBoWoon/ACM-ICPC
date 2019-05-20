#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, low, high, factory1, factory2;
bool visited[100001];
vector<pair<int, int> > v[100001];

bool bfs(int cost) {
    queue<int> q;
    q.push(factory1);
    visited[factory1] = true;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (here == factory2) {
            return true;
        }

        for (int i = 0; i < v[here].size(); i++) {
            int next = v[here][i].first;
            int nextCost = v[here][i].second;

            if (!visited[next] && cost <= nextCost) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return false;
}

int binarySearch(int low, int high) {
    while (low <= high) {
        memset(visited, false, sizeof(visited));

        int mid = (low + high) / 2;

        if (bfs(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));

        if (high < c) {
            high = c;
        }
    }

    scanf("%d %d", &factory1, &factory2);

    printf("%d\n", binarySearch(0, high));
}