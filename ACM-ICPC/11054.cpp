//
// Created by secret on 10/13/17.
//

#define LOCAL

#include <cstdio>

using namespace std;

int n, max;
int a[1001], dp[2][1001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int maxA = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (maxA < dp[0][j]) {
                    maxA = dp[0][j];
                }
            }
        }
        dp[0][i] = maxA + 1;
    }

    for (int i = n; i > 0; i--) {
        int maxA = 0;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) {
                if (maxA < dp[1][j]) {
                    maxA = dp[1][j];
                }
            }
        }
        if (dp[1][i] < maxA + 1) {
            dp[1][i] = maxA + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (max < dp[0][i] + dp[1][i]) {
            max = dp[0][i] + dp[1][i];
        }
    }

    printf("%d\n", max - 2);
}