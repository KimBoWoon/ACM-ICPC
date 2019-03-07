#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 101

typedef struct Report {
    int order, priority;
} report;

int t, n, m;

int main() {
    scanf("%d", &t);

    while (t--) {
        int answer = 0;
        // 큐는 문서 들어온 순서대로 저장
        // 우선순위 큐는 문서의 중요도를 저장
        // 문서의 중요도와 큐에 들어온 문서의 중요도가 같으면 출력
        queue<report> q;
        priority_queue<int> pq;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            q.push({ i, x });
            pq.push(x);
        }

        while (!q.empty()) {
            int priority = q.front().priority;
            int order = q.front().order;
            q.pop();

            if (pq.top() == priority) {
                answer++;
                pq.pop();
                if (order == m) {
                    break;
                }
            } else {
                q.push({ order, priority });
            }
        }
        printf("%d\n", answer);
    }
}