#include <bits/stdc++.h>

int arr[4];

int main() {
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

    std::sort(arr, arr + 4);

    printf("%d\n", arr[0] * arr[2]);
}