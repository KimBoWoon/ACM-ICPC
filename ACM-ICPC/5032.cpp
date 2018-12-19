#include <cstdio>

int e, c, f, temp, ans;

int main() {
    scanf("%d %d %d", &e, &f, &c);

    temp = e + f;

    while (true) {
        if (temp < c) {
            break;
        }
        ans += temp / c;
        temp = temp % c + temp / c;
    }

    printf("%d\n", ans);
}