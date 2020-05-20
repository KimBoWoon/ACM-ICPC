#include <bits/stdc++.h>
using namespace std;

int t, w, answer;
int tree[1001];
int dp[3][1001][32];

int main() {
    scanf("%d %d", &t, &w);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &tree[i]);
    }

    for (int i = 1; i <= t; i++) { // 초
        for (int j = 1; j <= w + 1; j++) { // 움직이는 횟수(움직이지 않는 경우도 포함)
            if (tree[i] == 1) { // 자두가 1번나무에서 떨어진다면
                dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1); // max(받아먹는다, 움직여서 받아먹는다)
                dp[2][i][j] = max(dp[2][i - 1][j], dp[1][i - 1][j - 1]); // max(움직이지않았을 경우, 움직였을 경우)
            } else { // 자두가 2번 나무에서 떨어진다
                if (i == 1 && j == 1) { // 처음 시작했을 때 2번에서 자두가 떨어진다면 첫번째는 넘어간다
                    continue;
                }

                dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]); // max(움직이지않았을 경우, 움직였을 경우)
                dp[2][i][j] = max(dp[2][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1); // max(받아먹는다, 움직여서 받아먹는다)
            }
        }
    }

    for (int i = 1; i <= w + 1; i++) {
        answer = max(answer, max(dp[1][t][i], dp[2][t][i]));
    }

    printf("%d\n", answer);
}