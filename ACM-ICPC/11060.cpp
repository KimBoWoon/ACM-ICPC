#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 987654321

int n;
int arr[1001], dp[1001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = MAX;
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) { // i번째 위치
        for (int j = 0; j <= arr[i]; j++) { // 점프할 수 있는 거리
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp[n - 1] == MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[n - 1]);
    }
}