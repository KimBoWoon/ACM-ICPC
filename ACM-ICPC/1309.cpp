//
// Created by secret on 6/24/17.
//

#include <cstdio>

#define MOD 9901

int n;
int dp[100001][3];

int main() {
    scanf("%d", &n);

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    printf("%d\n", dp[n][0]);
}