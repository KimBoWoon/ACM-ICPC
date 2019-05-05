#include <bits/stdc++.h>

int n, m;
int num[100001];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        num[i] = num[i - 1] + x;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x, y;

        scanf("%d %d", &x, &y);

        printf("%d\n", num[y] - num[x - 1]);
    }
}