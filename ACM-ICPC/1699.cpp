#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int dp[100001];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dp[i] = 1e5;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    printf("%d", dp[n]);

    return 0;
}

// n보다 작거나 같은 제곱수 이므로 제곱수만 확인
// min(현재값, 이전값 + 1)
// min(dp[i], dp[n - i * i] + 1)