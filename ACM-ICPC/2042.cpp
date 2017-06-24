//
// Created by secret on 6/24/17.
//

#include<stdio.h>

typedef unsigned long long ULLONG;
ULLONG bit[1000001], a[1000001];
int n, m, k;
ULLONG x, y, z;

void update(int h, ULLONG x) {
    for (int i = h; i <= n; i += i & -i) {
        bit[i] += x;
    }
}

ULLONG query(int h) {
    ULLONG r = 0;

    for (int i = h; i; i -= i & -i) {
        r += bit[i];
    }

    return r;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        update(i, a[i]);
    }

    for (int i = 0; i < m + k; i++) {
        scanf("%lld %lld %lld", &x, &y, &z);

        if (x == 1) {
            update(y, z - a[y]);
            a[y] = z;
        } else {
            printf("%lld\n", query(z) - query(y - 1));
        }
    }

    return 0;
}