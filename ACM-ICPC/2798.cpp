#include <cstdio>

int n, m, ans;
int card[101];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (card[i] + card[j] + card[k] <= m && m - (card[i] + card[j] + card[k]) < m - ans) {
                    ans = card[i] + card[j] + card[k];
                }
            }
        }
    }

    printf("%d\n", ans);
}