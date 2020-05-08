#include<cstdio>

#define MOD 1000000000

int n, k, dp[201];

int main() {
    scanf("%d %d", &n, &k);

    dp[0] = 1;

    for (int i = 1; i <= k; i++) { // k개의 숫자를 사용
        for (int j = 1; j <= n; j++) { // n까지의 합
            dp[j] = (dp[j - 1] + dp[j]) % MOD;
        }
    }

    printf("%d\n", dp[n]);
}