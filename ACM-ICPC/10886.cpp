//
// Created by secret on 6/30/17.
//

#include <cstdio>

int n, cnt;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        cnt += x;
    }

    printf("%s\n", (cnt < n) ? "Junhee is not cute!" : "Junhee is cute!");
}