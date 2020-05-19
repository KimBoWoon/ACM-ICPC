#include <cstdio>

int t, n, m;
int coin[21];

int main() {
    scanf("%d", &t);

    while (t--) {
        int dp[10001] = {0};

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
        }

        scanf("%d", &m);

        dp[0] = 1;
        for (int i = 0; i < n; i++) { // n개의 동전
            // m원을 만드는 경우의 수 구하기
		    // money[i]원 부터 시작하는 이유 : money[i]원 보다 작은 값은 당연히 money[i]원으로 만들 수 없기 때문
            for (int j = coin[i]; j <= m; j++) {
                // j원을 만드는 경우의 수
			    // 이전에 구해둔 경우의 수를 가지고 구하기
                dp[j] += dp[j - coin[i]];
            }
        }

        printf("%d\n", dp[m]);
    }
}