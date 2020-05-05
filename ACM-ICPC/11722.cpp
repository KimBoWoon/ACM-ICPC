#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v;
int dp[1001];

void lds(int &idx, int value) {
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
    int idx = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        lds(idx, -x);
    }

    printf("%d\n", idx);

    // for (int i = 0; i < n; i++) {
    //     int x;

    //     scanf("%d", &x);

    //     x *= -1;

    //     if (v.empty()) {
    //         v.push_back(x);
    //     } else if (v[v.size() - 1] < x) {
    //         v.push_back(x);
    //     } else if (v[v.size() - 1] > x) {
    //         vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
    //         *iter = x;
    //     }
    // }

    // printf("%ld\n", v.size());
}

// 감소하는 부분 수열 == 음수인 값들 중 LIS 구하기