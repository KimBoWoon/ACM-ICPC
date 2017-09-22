//
// Created by secret on 1/3/17.
//

#include <cstdio>

using namespace std;

int a[1010], ans[1010];
int n, max;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        int min = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (min < ans[j]) {
                    min = ans[j];
                }
            }
        }
        ans[i] = min + 1;
        if (max < ans[i])
            max = ans[i];
    }

    printf("%d\n", max);
}