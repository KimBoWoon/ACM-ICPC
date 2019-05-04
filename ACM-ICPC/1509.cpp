#include <bits/stdc++.h>

int s, e, n, m;
char str[2501];
int minCnt[2501];
int dp[2501][2501];

int check(int s, int e) {
    if (s >= e) {
        return 1;
    }

    int& ret = dp[s][e];

    if (ret != -1) {
        return ret;
    }

    if (str[s] != str[e]) {
        ret = 0;
    } else {
        ret = check(s + 1, e - 1);
    }

    return ret;
}

int main() {
    scanf("%s", str + 1);

    memset(dp, -1, sizeof(dp));

    int len = strlen(str + 1);

    for (int i = 1; i <= len; i++) {
        minCnt[i] = 987654321;

        for (int j = 1; j <= i; j++) {
            if (check(j, i)) {
                minCnt[i] = std::min(minCnt[i], minCnt[j - 1] + 1);
            }
        }
    }

    printf("%d\n", minCnt[len]);
}