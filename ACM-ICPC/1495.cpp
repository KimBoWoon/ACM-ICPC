#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, m, answer;
int v[101];
bool dp[101][1001];

int main() {
    scanf("%d %d %d", &n, &s, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    if (s + v[0] <= m) {
        dp[0][s + v[0]] = true;
    }
    if (s - v[0] >= 0) {
        dp[0][s - v[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j + v[i] <= m) {
                    dp[i][j + v[i]] = true;
                }
                if (j - v[i] >= 0) {
                    dp[i][j - v[i]] = true;
                }
            }
        }
    }

    for (int i = m; i >= 0; i--) {
        if (dp[n - 1][i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
}