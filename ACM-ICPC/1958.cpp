#include <bits/stdc++.h>

char str1[101], str2[101], str3[101];
int dp[101][101][101];

int main() {
    scanf("%s %s %s", &str1, &str2, &str3);

    for (int i = 1; i <= strlen(str1); i++) {
        for (int j = 1; j <= strlen(str2); j++) {
            for (int k = 1; k <= strlen(str3); k++) {
                if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = std::max(dp[i - 1][j - 1][k], std::max(dp[i - 1][j][k - 1], std::max(dp[1][j - 1][k - 1], std::max(dp[i - 1][j][k], std::max(dp[i][j - 1][k], dp[i][j][k - 1])))));
                }
            }
        }
    }

    printf("%d\n", dp[strlen(str1)][strlen(str2)][strlen(str3)]);
}