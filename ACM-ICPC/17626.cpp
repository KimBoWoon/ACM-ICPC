#include <cstdio>
using namespace std;

int n;
int dp[50001];

/*
i를 (j * j)로 만들 수 있는 최소값

dp[i] : 현재 값
dp[i - j * j] : j * j로 i를 만들 수 있는 최소값
*/

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dp[i] = 2e6;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = (dp[i] < dp[i - j * j] + 1) ? dp[i] : dp[i - j * j] + 1;
        }
    }

    printf("%d\n", dp[n]);
}