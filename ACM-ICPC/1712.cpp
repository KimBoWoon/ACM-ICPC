#include <cstdio>

/*
A + B * x < C * x
= A < C * x - B * x
= A < (C - B) * x
= A / (C - B) < x
*/

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (c - b <= 0) {
        printf("-1\n");
    } else {
        printf("%d\n", a / (c - b) + 1);
    }
}