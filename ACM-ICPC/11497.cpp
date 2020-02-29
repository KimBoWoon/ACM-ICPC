#include <cstdio>
#include <algorithm>
using namespace std;

int t, n;
int arr[10001], a[10001];

int main() {
    scanf("%d", &t);

    while (t--) {
        int answer = 0, x, y;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr + n);

        x = 0, y = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[x++] = arr[i];
            } else {
                a[y--] = arr[i];
            }
        }

        a[n] = a[0];
        for (int i = 0; i < n; i++) {
            if (answer < abs(a[i] - a[i + 1])) {
                answer = abs(a[i] - a[i + 1]);
            }
        }

        printf("%d\n", answer);
    }
}

// 원형으로 통나무를 배치하므로 정렬한뒤에 왼쪽, 오른쪽에 나눠 통나무를 넣어준뒤 계산한다.