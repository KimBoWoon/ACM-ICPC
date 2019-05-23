#include <bits/stdc++.h>

int n, m;
int jewelry[300001];

int binarySearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2, sum = 0;

        for (int i = 0; i < m; i++) {
            sum += jewelry[i] / mid;
            if (jewelry[i] % mid != 0) {
                sum++;
            }
        }

        if (sum > n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &jewelry[i]);
    }

    printf("%d\n", binarySearch(0, INT_MAX));
}