#include <bits/stdc++.h>

typedef unsigned long long ULLONG;

int n;
ULLONG dp[100];

ULLONG topDown(int x) {
    if (x == 0) {
        return dp[0] = 0;
    }
    if (x == 1) {
        return dp[1] = 1;
    }

    if (dp[x] != 0) {
        return dp[x];
    }

    return dp[x] = topDown(x - 1) + topDown(x - 2);
}

ULLONG bottomUp(int x) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    scanf("%d", &n);

    memset(dp, 0, sizeof(dp));
    printf("%lld\n", topDown(n));
    // printf("%lld\n", bottomUp(n));

    return 0;
}