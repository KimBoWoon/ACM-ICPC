//
// Created by null on 11/12/17.
//

#define LOCAL

#include <cstdio>
#include <cstring>

int arr[31];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 28; i++) {
        int x;
        scanf("%d", &x);
        arr[x] = x;
    }

    for (int i = 1; i <= 30; i++) {
        if (arr[i] == 0) {
            printf("%d\n", i);
        }
    }
}