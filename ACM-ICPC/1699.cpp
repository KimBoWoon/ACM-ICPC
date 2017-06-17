//
// Created by secret on 6/17/17.
//

#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int dp[100001];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dp[i] = 1e5;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    printf("%d", dp[n]);

    return 0;
}