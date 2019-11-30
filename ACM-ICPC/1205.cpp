#include <cstdio>
using namespace std;

int p, n, score, idx, x;

int main() {
    scanf("%d %d %d", &n, &score, &p);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);

        if (x > score) {
            idx++;
        } else if (x < score) {
            printf("%d\n", idx + 1);
            return 0;
        }
    }

    if (n < p) {
        printf("%d\n", idx + 1);
    } else {
        printf("-1\n");
    }
}