#include <bits/stdc++.h>

int n;
int left[2001], right[2001];
int dp[2001][2001];

int f(int x, int y) {
    if (x == n || y == n) {
        return 0;
    }

    int& ret = dp[x][y];

    if (ret != -1) {
        return ret;
    }

    ret = std::max(f(x + 1, y), f(x + 1, y + 1));

    if (left[x] > right[y]) {
        ret = std::max(ret, f(x, y + 1) + right[y]);
    }

    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &left[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &right[i]);
    }

    memset(dp, -1, sizeof(dp));
    
    printf("%d\n", f(0, 0));
}