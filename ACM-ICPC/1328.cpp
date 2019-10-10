#include <cstdio>
using namespace std;

int n, l, r;
long long dp[101][101][101];

/*
양쪽 사이드에 배치하면 무조건 증가
하지만 그 사이에 배치하면 변화 없음
그러면 양 사이드를 제외하고 어디든 배치할 수 있으므로
dp[n - 1][l - 1][r] : 왼쪽에 배치
dp[n - 1][l][r - 1] : 오른쪽에 배치
dp[n - 1][l][r] * (n - 2) : 양 사이드에 배치
모두 더하면 된다
*/

int main() {
    scanf("%d %d %d", &n, &l, &r);
    dp[1][1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            for (int k = 1; k <= r; k++) {
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (n - 2);
                dp[i][j][k] %= 1000000007;
            }
        }
    }

    printf("%lld\n", dp[n][l][r]);
}