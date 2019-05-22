#include <bits/stdc++.h>

int x, n;
int lego[1000001];

void binarySearch() {
    // 하나의 값을 선택하고 필요한 길이에서 뺀 뒤 나머길이를 이분 탐색 한다
    for (int i = 0; i < n - 1; i++) {
        int cur = lego[i];

        if (std::binary_search(lego + i + 1, lego + n, x - cur)) {
            printf("yes %d %d\n", cur, x - cur);
            return;
        }
    }
    printf("danger\n");
}

int main() {
    while (scanf("%d", &x) == 1) {
        scanf("%d", &n);

        x *= 10000000;

        for (int i = 0; i < n; i++) {
            scanf("%d", &lego[i]);
        }

        std::sort(lego, lego + n);

        binarySearch();
    }
}