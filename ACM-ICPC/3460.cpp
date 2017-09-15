//
// Created by secret on 9/15/17.
//

#include <cstdio>

int testCase;
int n;

int main() {
    scanf("%d", &testCase);

    while (testCase--) {
        scanf("%d", &n);

        for (int idx = 0; n != 0; ) {
            if (n & 1) {
                printf("%d ", idx);
            }
            n >>= 1;
            idx++;
        }
    }
}