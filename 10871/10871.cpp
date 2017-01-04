//
// Created by secret on 1/3/17.
//

#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int ans[10001];
int n, x, t, cnt;

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);

        if (t < x) {
            ans[cnt++] = t;
        }
    }

    for (int i = 0; i < cnt; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}