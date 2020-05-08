#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, answer;
int dp[10001];
pair<int, int> state[101];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &state[i].first);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &state[i].second);
    }

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for (int i = 0; i < n; i++) { // i : i번째 앱까지 활성화 되어 있을 때
        for (int j = 10001; j >= 0; j--) { // j : 비용
            if (dp[j] != -1 && dp[j + state[i].second] < dp[j] + state[i].first) { // 현재 비용에서 다음 비용까지 사용하여 만들수있는 메모리의 최대값
                dp[j + state[i].second] = dp[j] + state[i].first;
            }
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= m) {
            printf("%d\n", i);
            return 0;
        }
    }
}

// int n, m, x, answer;
// int dp[101][10001];
// pair<int, int> state[101];

// int main() {
//     scanf("%d %d", &n, &m);

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &state[i].first);
//     }

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &state[i].second);
//     }

//     answer = 2e9;
//     dp[0][state[0].second] = state[0].first;
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j <= 10000; j++) {
//             if (j - state[i].second >= 0) {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - state[i].second] + state[i].first);
//             }

//             dp[i][j] = max(dp[i][j], dp[i - 1][j]);

//             if (dp[i][j] >= m) {
//                 answer = min(answer, j);
//             }
//         }
//     }

//     printf("%d\n", answer);

//     return 0;
// }