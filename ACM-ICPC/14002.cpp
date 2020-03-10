#include <cstdio>
using namespace std;

int n, idx, position;;
int arr[1001], dp[1001], v[1001];

void go(int idx) {
    if (idx == 0) {
        return;
    }

    go(v[idx]);
    printf("%d ", arr[idx]);
}

void lis(int& idx, int value) {
    // value값이 마지막 값보다 크면 뒤에 삽입
    if (idx == 0 || (idx > 0 && dp[idx - 1] <= value)) {
        dp[idx++] = value;
        return;
    }

    // 아니면 이분탐색을 시작하여 최적의 위치 탐색
    // lower_bound(start, end, target)을 사용할 수도 있다
    // target보다 큰 가장 작은 정수를 찾아 교체한다
    int start = 0, end = idx - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (dp[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // 값을 대체
    dp[end + 1] = value;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     lis(idx, arr[i]);
    // }

    for (int i = 1; i <= n; i++) {
        if (idx < dp[i]) {
            idx = dp[i];
            position = i;
        }
    }
    printf("%d\n", idx);
    go(position);
    printf("\n");
}