#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_SIZE 10001

int n, parent, child, cost, maxCost, position;
int visit[MAX_SIZE], sum[MAX_SIZE];
vector<pair<int, int> > tree[MAX_SIZE];
queue<int> q;

int bfs(int start) {
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        visit[node] = 1;
        q.pop();

        for (int i = 0; i < tree[node].size(); i++) {
            // 아직 방문하지 않은 노드
            if (visit[tree[node][i].first] == 0) {
                q.push(tree[node][i].first);

                // 해당하는 노드의 sum은 가중치 + 부모 노드의 누적합 
                sum[tree[node][i].first] += tree[node][i].second + sum[node];
 
                // 해당하는 노드의 sum이 최대인지 확인한다.
                if (sum[tree[node][i].first] > maxCost) {
                    maxCost = sum[tree[node][i].first];
                    position = tree[node][i].first;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &parent, &child, &cost);
        tree[parent].push_back(make_pair(child, cost));
        tree[child].push_back(make_pair(parent, cost));
    }

    // 루트에서 시작해서 제일 멀리 있는 노드
    bfs(1);
    // 초기화
    fill(visit, visit + MAX_SIZE, 0);
    fill(sum, sum + MAX_SIZE, 0);
    maxCost = 0;
    // 루트에서 제일 멀리있는 노드에서 시작해서 제일 멀리 있는 노드가 트리의 지름이 된다.
    bfs(position);

    printf("%d\n", maxCost);
}