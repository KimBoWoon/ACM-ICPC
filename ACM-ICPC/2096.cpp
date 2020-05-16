//
// Created by secret on 6/24/17.
//

#include  <cstdio>
#include <algorithm>

using namespace std;

int n, x, y, z;
int dp[100001][3][2];

int main(void) {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x, &y, &z);

        // 최대값
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + x; // 왼쪽, 가운데
        dp[i][1][0] = max(max(dp[i - 1][0][0], dp[i - 1][1][0]), dp[i - 1][2][0]) + y; // 왼쪽, 가운데, 오른쪽
        dp[i][2][0] = max(dp[i - 1][1][0], dp[i - 1][2][0]) + z;// 가운데, 오른쪽

        // 최소값
        dp[i][0][1] = min(dp[i - 1][0][1], dp[i - 1][1][1]) + x; // 왼쪽, 가운데
        dp[i][1][1] = min(min(dp[i - 1][0][1], dp[i - 1][1][1]), dp[i - 1][2][1]) + y;// 왼쪽, 가운데, 오른쪽
        dp[i][2][1] = min(dp[i - 1][1][1], dp[i - 1][2][1]) + z; // 가운데, 오른쪽
    }

    printf("%d %d\n", max(max(dp[n][0][0], dp[n][1][0]), dp[n][2][0]), min(min(dp[n][0][1], dp[n][1][1]), dp[n][2][1]));

    return 0;
}