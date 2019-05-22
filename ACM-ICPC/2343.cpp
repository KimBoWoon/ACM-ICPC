#include <bits/stdc++.h>

int n, m, left, right;
int lesson[100001];

int binarySearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2, sum = 0, blulay = 1;

        // mid라는 길이를 정해두고
        // 이 길이를 넘어가면 새로운 블루레이에 저장
        for (int i = 0; i < n; i++) {
            if (sum + lesson[i] > mid) {
                sum = 0;
                blulay++;
            }
            sum += lesson[i];
        }

        if (blulay > m) {
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
        scanf("%d", &lesson[i]);

        if (lesson[i] > left) {
            left = lesson[i];
        }
    }

    right = 2e9;

    printf("%d\n", binarySearch(left, right));
}