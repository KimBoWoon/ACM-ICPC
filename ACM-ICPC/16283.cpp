#include <bits/stdc++.h>

int a, b, n, w, cnt, answerI, answerJ;

int main() {
    scanf("%d %d %d %d", &a, &b, &n, &w);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if ((a * i) + (b * j) == w && i + j == n) {
                answerI = i;
                answerJ = j;
                cnt++;
            }
        }
    }

    if (cnt != 1) {
        printf("-1\n");
    } else {
        printf("%d %d\n", answerI, answerJ);
    }
}