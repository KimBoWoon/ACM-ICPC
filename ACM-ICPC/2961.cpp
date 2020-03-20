#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef unsigned long long ULLONG;

int n, answer = 2e9;
pair<int, int> ingredient[11];
bool visited[11];

void findAns(int cnt, int idx, int mul, int sum) {
    // 재료를 하나라도 선택했을 경우
    if (cnt >= 1) {
        answer = min(answer, abs(mul - sum));
    }
 
    for (int i = idx; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            findAns(cnt + 1, i, mul * ingredient[i].first, sum + ingredient[i].second);
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ingredient[i].first, &ingredient[i].second);
    }

    findAns(0, 0, 1, 0);

    printf("%d\n", answer);
}