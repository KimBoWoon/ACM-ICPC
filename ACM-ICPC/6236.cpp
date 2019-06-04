#include <bits/stdc++.h>

int n, m, left, right;
int money[100001];

int binarySearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2, k = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            if (k + money[i] > mid) {
                k = 0;
                cnt++;
            }
            k += money[i];
        }

        if (k != 0) {
            cnt++;
        }

        if (cnt > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &money[i]);

        left = std::max(left, money[i]);
        right += money[i];
    }

    printf("%d\n", binarySearch(left, right));
}