//
// Created by null on 12/5/17.
//

#include <cstdio>

int a, b, c, d, sum;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    sum = a + b + c + d;

    printf("%d\n%d\n", sum / 60, sum % 60);
}