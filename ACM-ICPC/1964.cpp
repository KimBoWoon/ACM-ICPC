//
// Created by null on 11/18/17.
//

#define LOCAL

#include <cstdio>
using namespace std;

int dp[10000001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;

    scanf("%d", &n);

    dp[1] = 5;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + ((i + 1) * 3 - 2);
        dp[i] %= 45678;
    }

    printf("%d\n", dp[n]);
}