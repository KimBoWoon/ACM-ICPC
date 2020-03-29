#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int t, v, e;
vector<int> vec[20001];

bool bfs() {
    queue<int> q;
    int colors[20001] = { 0 };

    // 이분 그래프란 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프
    // 모든 정점에서 bfs 탐색을 해서 이분 그래프 인지 확인한다
    // 간선이 연결 되지 않아도 이분 그래프의 조건만 무시 하지 않는다면 이분 그래프가 맞다
    for (int i = 1; i <= v; i++) {
        if (colors[i] == 0) { // 아직 방문하지 않았다면 bfs 탐색 시작
            q.push(i);
            colors[i] = 1;

            while (!q.empty()) {
                int here = q.front();
                q.pop();

                for (int j = 0; j < vec[here].size(); j++) {
                    if (colors[vec[here][j]] == 0) { // 아직 방문하지 않았다면
                        q.push(vec[here][j]);
                        colors[vec[here][j]] = colors[here] * -1;
                    } else if (colors[here] + colors[vec[here][j]] != 0) { // 인접한 정점끼리 더한 값이 0이 나오지 않으면 이분 그래프가 아니다
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &v, &e);

        for (int i = 0; i < e; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        if (bfs()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        for (int i = 1; i <= v; i++) {
            vec[i].clear();
        }
    }
}