//
// Created by null on 11/5/17.
//

#define LOCAL

#include <cstdio>

int n, r, e, c;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d %d", &r, &e, &c);

        if (r < e - c) {
            printf("advertise\n");
        } else if (r > e - c) {
            printf("do not advertise\n");
        } else {
            printf("does not matter\n");
        }
    }
}