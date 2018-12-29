#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define SIZE 1001
#define INF 1000000000

int a[SIZE][SIZE], visit[SIZE], dist[SIZE];
int start, destination, n, m;

void dijkstra() {
	int min, v;

	dist[start] = 0;

	for (int i = 1; i <= n; i++) {
		min = INF;

		for (int j = 1; j <= n; j++) {
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;

		for (int j = 1; j <= n; j++) {
			if (dist[j] > dist[v] + a[v][j]) {
				dist[j] = dist[v] + a[v][j];
			}
		}
	}
}

void dijkstra2() {
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

        for (int i = 1; i <= n; i++) {
            if (a[here][i] == -1 || dist[i] != -1) {
                continue;
            }

            pq.push({ -cost - a[here][i], i });
        }
    }
}

int main(void) {
	int from, to, w;

	scanf("%d %d", &n, &m);

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			a[x][y] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d %d", &from, &to);
		if (a[from][to] != INF) {
			scanf("%d", &temp);
			if (a[from][to] > temp)
				a[from][to] = temp;
		}
		else
			scanf("%d", &a[from][to]);
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	scanf("%d %d", &start, &destination);

	dijkstra2();

	printf("%d \n", dist[destination]);

	return 0;
}