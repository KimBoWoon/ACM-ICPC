#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Jewelry {
    int weight, price;
} jewelry;
typedef unsigned long long ULLONG;

int n, k;
ULLONG answer;
int c[300001];
jewelry j[300001];
// pair<int, int> j[300001];
priority_queue<int> pq;

bool comp(const jewelry &x, const jewelry &y) {
    return x.weight < y.weight;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &j[i].weight, &j[i].price);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
    }

    sort(j, j + n, comp);
    sort(c, c + k);

    for (int i = 0, x = 0; i < k; i++) {
        // 현재 가방에 들어갈 수 있는 모든 보석들을 우선순위 큐에 넣어준다
        // 맥스힙이므로 최고값이 루트에 있는다
        while (x < n && j[x].weight <= c[i]) {
            pq.push(j[x++].price);
        }

        // 루트를 제거하면 제일 값 비싼 보석을 가방에 넣은 것이 된다
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    printf("%lld\n", answer);
}