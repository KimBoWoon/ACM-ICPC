#include <cstdio>

int n, ans;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}