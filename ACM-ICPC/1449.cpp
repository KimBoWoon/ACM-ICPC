#include <bits/stdc++.h>

int n, l;
int arr[1001];

int main() {
    scanf("%d %d", &n, &l);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    std::sort(arr, arr + n);

    int temp = arr[0], cnt = 1;

    // temp에서 l까지 테이프로 붙이고 이 값이 다음 값보다 작을 때 까지 반복한다
    // 왜냐하면 그 전까지는 테이프를 붙여서 해결했으니까
    // -1은 -0.5에서 0.5까지 더 필요하기 하기 때문이다
    for (int i = 0; i < n; i++) {
        if (temp + l - 1 < arr[i]) {
            temp = arr[i];
            cnt++;
        }
    }

    printf("%d\n", cnt);
}