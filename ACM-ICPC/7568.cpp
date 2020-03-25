#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Person {
    int kg, cm;
} person;

int n;
vector<person> v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({ x, y });
    }

    // 하나의 기준을 잡고 모든 경우의 수 탐색
    for (int i = 0; i < n; i++) {
        int ranking = 0;

        for (int j = 0; j < n; j++) {
            // 기준에 대해 몸무게와 키가 크다면 순위 증가
            if (v[i].kg < v[j].kg && v[i].cm < v[j].cm) {
                ranking++;
            }
        }
        printf("%d ", ranking + 1);
    }
    printf("\n");
}