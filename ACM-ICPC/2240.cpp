#include <bits/stdc++.h>

int t, w, answer;
int tree[1001];
int dp[3][1001][32];

int main() {
    scanf("%d %d", &t, &w);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &tree[i]);
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= w + 1; j++) {
            if (tree[i] == 1) {
                dp[1][i][j] = std::max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
                dp[2][i][j] = std::max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
            } else {
                if (i == 1 && j == 1) {
                    continue;
                }
                dp[1][i][j] = std::max(dp[2][i - 1][j - 1], dp[1][i - 1][j]);
                dp[2][i][j] = std::max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
            }
        }
    }
    for (int i = 1; i <= w + 1; i++) {
        answer = std::max(answer, std::max(dp[1][t][i], dp[2][t][i]));
    }
    printf("%d\n", answer);
}