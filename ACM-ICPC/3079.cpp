#include <bits/stdc++.h>
using namespace std;

typedef long long LLONG;

int n, m;
int desk[100001];

LLONG binarySearch(LLONG left, LLONG right) {
    while (left <= right) {
        LLONG mid = (left + right) / 2, sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mid / desk[i];
        }

        // printf("left : %lld ", left);
        // printf("mid : %lld ", mid);
        // printf("sum : %lld ", sum);
        // printf("right : %lld\n", right);

        if (sum >= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &desk[i]);
    }

    printf("%lld\n", binarySearch(1, 1000000000000000000));
}