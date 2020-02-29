#include <cstdio>
#include <algorithm>
using namespace std;

int n, sum;
int score[10001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }

    sort(score, score + n);

    for (int i = 0; i < n; i++) {
        sum += score[i];

        if (sum < i * (i + 1) / 2) {
            printf("-1\n");
            return 0;
        }
    }

    if (sum == n * (n - 1) / 2) {
        printf("1\n");
    } else {
        printf("-1\n");
    }
}

// 랑주의 이론을 알아야 풀 수 있는 문제
// 1. score[k] >= k * (k - 1) / 2
// 2. score의 합 == n * (n - 1) / 2
// 를 만족하면 유효한 점수