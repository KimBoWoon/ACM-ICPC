//
// Created by secret on 10/11/16.
//

#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

unsigned long long arr[100];

int main() {
    int n;

    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    printf("%lld\n", arr[n]);

    return 0;
}