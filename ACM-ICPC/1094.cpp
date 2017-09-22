//
// Created by secret on 4/3/17.
//

#include <cstdio>

using namespace std;

int main() {
    int stick = 64, n, ans = 0;

    scanf("%d", &n);

    while (n != 0) {
        if (stick > n) {
            stick /= 2;
        }
        else {
            n -= stick;
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}