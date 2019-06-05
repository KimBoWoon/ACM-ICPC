#include <bits/stdc++.h>
using namespace std;

int n, m, maxVertex, maxDist, cnt;
int dist[20001];
vector<pair<int, int> > v[20001];
priority_queue<pair<int, int> > q;

void dijkstra(int start) {
    dist[start] = 0;
    q.push(make_pair(0, start));

    while (!q.empty()) {
        pair<int, int> value = q.top();
        q.pop();

        int current = value.second;
        int cost = -value.first;

        if (dist[current] < cost) {
            continue;
        }

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i].second;
            int nextCost = v[current][i].first + dist[current];

            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                q.push(make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(make_pair(1, y));
        v[y].push_back(make_pair(1, x));
    }

    fill(dist, dist + 20001, INT_MAX);

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        if (maxDist < dist[i]) {
            maxVertex = i;
            maxDist = dist[i];
            cnt = 0;
        }
        if (maxDist == dist[i]) {
            cnt++;
        }
    }

    printf("%d %d %d\n", maxVertex, maxDist, cnt);
}