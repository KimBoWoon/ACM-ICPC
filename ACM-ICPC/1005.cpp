#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

#define SIZE 5000

int t, n, k, w;
int indegree[SIZE];
int cost[SIZE], time[SIZE];
vector<int> graph[SIZE];

/*
1) indegree(진입차수) 가 0인 점을 큐에 넣고 탐색을 시작한다.
2) 현재점과 연결된 정점의 진입차수를 1 감소시킨다.
3) 그 중 진입차수가 0이 되는 점을 큐에 넣고 반복
진입차수가 0인 점을 넣는 순서가 위상정렬의 순서이다.
*/
void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) { // 현재 진입차수가 0인 점을 큐에 넣음
            q.push(i);
        }
    }

    while (indegree[w] > 0) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i];
            indegree[there]--; // 연결된 곳의 차수를 1씩 감소해준다.
            cost[there] = max(cost[there], cost[here] + time[here]);
            if (indegree[there] == 0) { // 다시 0인 곳을 큐에 넣음
                q.push(there);
            }
        }
    }

    printf("%d\n", cost[w] + time[w]);
}

int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &time[i]);
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b); // a가 b앞에 와야 한다.
            indegree[b]++;         // b의 진입차수 증가
        }

        scanf("%d", &w);

        bfs();

        memset(indegree, 0, SIZE);
        memset(cost, 0, SIZE);
        memset(time, 0, SIZE);
        for (int i = 0; i <= n; i++) {
            graph[i].clear();
        }
    }

    return 0;
}