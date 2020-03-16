#include <cstdio>
using namespace std;

typedef long long LLONG;

int n;
LLONG dp[61][61];

LLONG split(int w, int h) {
    // 메모이제이션
    if (dp[w][h]) {
        return dp[w][h];
    }

    // 온전한 알약이 없으면 무조건 쪼개진 것을 먹어야 하기 때문에 한 가지 경우 밖에 없다
    if (w == 0) {
        return 1;
    }

    // 하나의 알약을 쪼개 먹는다
    dp[w][h] = split(w - 1, h + 1);

    // 쪼개진 알약을 먹는다
    if (h > 0) {
        dp[w][h] += split(w, h - 1);
    }

    return dp[w][h];
}

int main() {
    while (true) {
        scanf("%d", &n);

        if (n == 0) {
            return 0;
        }

        printf("%lld\n", split(n - 1, 1));
    }
}