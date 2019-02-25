#include <cstdio>

using namespace std;

int n, answer;
int value[1001], dp[2][1001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        for (int j = 0; j < i; j++) {
            if (value[i] > value[j] && dp[0][i] < dp[0][j] + 1) {
                dp[0][i] = dp[0][j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        dp[1][i] = 0;
        for (int j = n - 1; j >= i; j--) {
            if (value[i] > value[j] && dp[1][i] < dp[1][j] + 1) {
                dp[1][i] = dp[1][j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (answer < dp[0][i] + dp[1][i]) {
            answer = dp[0][i] + dp[1][i];
        }
    }

    printf("%d\n", answer);
}