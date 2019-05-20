#include <bits/stdc++.h>
using namespace std;

int n, k, answer;

int binarySearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2, cnt = 0;

        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }

        if (cnt < k) {
            left = mid + 1;
        } else {
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}

int main() {
    scanf("%d %d", &n, &k);

    printf("%d\n", binarySearch(1, k));
}