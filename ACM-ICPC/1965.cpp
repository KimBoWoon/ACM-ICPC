#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, idx;
int dp[1001];
vector<int> v;

void lis(int value) {
    if (idx == 0 || (idx > 0 && dp[idx - 1] < value)) {
        dp[idx++] = value;
        return;
    }

    int start = 0, end = idx - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (dp[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    dp[end + 1] = value;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        lis(x);
    }

    printf("%d\n", idx);
    // scanf("%d", &n);

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

    // printf("%ld\n", v.size());
}

// LIS 문제
// 뒤에 상자가 커야하기 때문에 LIS 조건문이
// if (idx == 0 || (idx > 0 && dp[idx - 1] < value)) 이다