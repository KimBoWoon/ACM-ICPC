//
// Created by secret on 7/2/17.
//

#include<cstdio>

#define MOD 1000000000

int n, k, dp[201];

int main() {
    scanf("%d %d", &n, &k);

    dp[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] = (dp[j - 1] + dp[j]) % MOD;
        }
    }

    printf("%d", dp[n]);
}