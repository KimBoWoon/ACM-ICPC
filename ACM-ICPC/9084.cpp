//
// Created by null on 11/11/17.
//

#define LOCAL

#include <cstdio>

int t, n, m;
int coin[21];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        int dp[10001] = {0};

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
        }

        scanf("%d", &m);

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        printf("%d\n", dp[m]);
    }
}