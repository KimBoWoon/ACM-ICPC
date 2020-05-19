#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, maxValue, idx;
int arr[201], dp[201];
vector<int> v;

// lis 이분탐색
void lis(int x) {
    if (idx == 0 || (idx > 0 && dp[idx - 1] < x)) {
        dp[idx++] = x;
        return;
    }

    int start = 0, end = idx - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (dp[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    dp[end + 1] = x;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        lis(x);
    }

    printf("%d\n", n - idx);

    // lis n^2
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &arr[i]);
    // }

    // for (int i = 0; i < n; i++) {
    //     dp[i] = 1;

    //     for (int j = 0; j < i; j++) {
    //         if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
    //             dp[i]++;
    //         }
    //     }

    //     if (maxValue < dp[i]) {
    //         maxValue = dp[i];
    //     }
    // }

    // printf("%d\n", n - maxValue);

    // lis lower_bound사용
    // for (int i = 0; i < n; i++) {
    //     int x;

    //     scanf("%d", &x);

    //     if (v.empty()) {
    //         v.push_back(x);
    //     } else if (v[v.size() - 1] < x) {
    //         v.push_back(x);
    //     } else if (v[v.size() - 1] > x) {
    //         vector<int>::iterator idx = lower_bound(v.begin(), v.end(), x);
    //         *idx = x;
    //     }
    // }

    // printf("%d\n", n - v.size());
}

// 오름차순 정렬하는 문제이다
// 그러므로 원래 오름차순 되어 있는 부분은 변경할 필요가 없다
// 그래서 n - lis의 길이가 정답