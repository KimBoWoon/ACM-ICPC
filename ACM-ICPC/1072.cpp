#include <bits/stdc++.h>
using namespace std;

typedef long long LLONG;
LLONG x, y, z;

LLONG binarySearch(LLONG left, LLONG right) {
    while (left <= right) {
        LLONG mid = (left + right) / 2, temp = 100 * (y + mid) / (x + mid);

        if (z < temp) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    scanf("%lld %lld", &x, &y);

    z = 100 * y / x;

    if (z >= 99) {
        printf("-1\n");
    } else {
        printf("%lld\n", binarySearch(0, 2e9));
    }
}