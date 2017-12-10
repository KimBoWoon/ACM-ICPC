//
// Created by null on 12/10/17.
//

#include <cstdio>

int a, b, c, d, l, ans;

int main() {
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

    while (a > 0 || b > 0) {
        a -= c;
        b -= d;
        ans++;
    }

    printf("%d\n", l - ans);
}