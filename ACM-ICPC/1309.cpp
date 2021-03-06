#include <cstdio>

#define MOD 9901

int n;
int dp[100001][3];

int main() {
    scanf("%d", &n);

    dp[0][0] = dp[0][1] = dp[0][2] = 1; // 모두 미배치, 왼쪽에만 배치, 오른쪽에만 배치

    // i번째 줄이 미배치라면 윗줄 모두 미배치, 왼쪽에만, 오른쪽에만 배치가능
    // i번째 줄이 왼쪽에만 배치했다면 윗줄 모두 미배치, 오른쪽에만 배치가능
    // i번째 줄이 오른쪽에만 매치했다면 웟줄 모두 미배치, 왼쪽에만 배치가능
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    printf("%d\n", dp[n][0]);
}