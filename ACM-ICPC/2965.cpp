//
// Created by null on 11/21/17.
//

#include <cstdio>

int x, y, z;

int main() {
    scanf("%d %d %d", &x, &y, &z);

    printf("%d\n", (y - x > z - y) ? y - x - 1 : z - y - 1);
}