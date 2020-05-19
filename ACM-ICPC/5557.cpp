#include <cstdio>
using namespace std;

int n;
int arr[101];
long dp[101][21];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[1][arr[1]] = 1; // 첫번째 숫자로 만들 수 있는 경우의 수

    for (int i = 1; i <= n - 1; i++) { // i번째 수
        for (int j = 0; j <= 20; j++) { // 범위
            if (dp[i][j] > 0) {
                if (j + arr[i + 1] >= 0 && j + arr[i + 1] <= 20) {
                    dp[i + 1][j + arr[i + 1]] += dp[i][j];
                }
                if (j - arr[i + 1] >= 0 && j - arr[i + 1] <= 20) {
                    dp[i + 1][j - arr[i + 1]] += dp[i][j];
                }
            }
        }
    }

    printf("%ld\n", dp[n - 1][arr[n]]);
}