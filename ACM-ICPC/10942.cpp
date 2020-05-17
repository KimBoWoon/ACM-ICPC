#include <cstdio>
#include <cstring>

int s, e, n, m;
int arr[2001];
// int dp[2001][2001];
bool dp[2001][2001];

// int check(int s, int e) {
//     if (s >= e) {
//         return 1;
//     }

//     int& ret = dp[s][e];

//     if (ret != -1) {
//         return ret;
//     }

//     if (arr[s] != arr[e]) {
//         return 0;
//     }

//     ret = check(s + 1, e - 1);

//     return ret;
// }

void solution() {
    //길이 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    //길이 2
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    //길이 3 이상
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            //앞 뒤가 같고, 앞 뒤 사이에 있는 수들이 팰린드롬인 경우
            if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) {
                dp[j][j + i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);
    // memset(dp, -1, sizeof(dp));
    memset(dp, false, sizeof(dp));

    solution();

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);

        if (dp[s - 1][e - 1]) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        
        // if (check(s - 1, e - 1)) {
        //     printf("1\n");
        // } else {
        //     printf("0\n");
        // }
    }
}