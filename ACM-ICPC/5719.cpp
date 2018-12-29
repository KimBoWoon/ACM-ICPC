#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define SIZE 501

int n, m, start, destination;
int map[SIZE][SIZE];
int dist[SIZE];

void dijkstra() {
    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int, int> > pq;
    pq.push({ 0, start });

    while (pq.size()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[here] != -1) {
            continue;
        }

        dist[here] = cost;

        for (int i = 0; i < n; i++) {
            if (map[here][i] == -1 || dist[i] != -1) {
                continue;
            }

            pq.push({ -cost - map[here][i], i });
        }
    }
}

void eraseEdge() {
    queue<int> qu;
    qu.push(destination);

    while (qu.size()) {
        int cx = qu.front();
        qu.pop();

        for (int i = 0; i < n; i++) {
            if (dist[cx] == dist[i] + map[i][cx] && map[i][cx] != -1) {
                map[i][cx] = -1;
                qu.push(i);
            }    
        }
    }
}

int main() {
    while (true) {
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            return 0;
        }

        scanf("%d %d", &start, &destination);
        memset(map, -1, sizeof(map));

        for (int i = 0; i < m; i++) {
            int x, y, cost;
            scanf("%d %d %d", &x, &y, &cost);
            map[x][y] = cost;
        }

        dijkstra();
        eraseEdge();
        dijkstra();

        printf("%d\n", dist[destination]);
    }

    return 0;
}