#include <cstdio>
using namespace std;

int s, e, n, m;
int arr[2001];
int dp[2001][2001];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // 길이가 1
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    // 길이가 2
    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    // 길이가 3 이상
    for (int x = 3; x <= n; x++) {
        for (int i = 1; i <= n - x + 1; i++) {
            int j = i + x - 1;

            if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
            }
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}