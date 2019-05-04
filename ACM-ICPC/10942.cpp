#include <bits/stdc++.h>

int s, e, n, m;
int arr[2001];
int dp[2001][2001];

int check(int s, int e) {
    if (s >= e) {
        return 1;
    }

    int& ret = dp[s][e];

    if (ret != -1) {
        return ret;
    }

    if (arr[s] != arr[e]) {
        return 0;
    }

    ret = check(s + 1, e - 1);

    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    memset(dp, -1, sizeof(dp));

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        
        if (check(s - 1, e - 1)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}