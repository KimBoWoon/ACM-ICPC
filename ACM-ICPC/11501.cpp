#include <cstdio>
using namespace std;

typedef long long LLONG;

int t;
int arr[1000001];

int main() {
    scanf("%d", &t);

    while (t--) {
        int n;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        LLONG x = 0, y = 0;

        for (int i = n - 1; i != -1; i--) {
            if (x < arr[i]) {
                x = arr[i];
            }
            if (x > arr[i]) {
                y += (x - arr[i]);
            }
        }

        printf("%lld\n", y);
    }
}

// 첫째날 보다 마지막날 부터 계산하는게 쉽다.
// 1 2 3 4 이면 최댓값이 4이고 3 2 1 으로 줄어들고 있으므로
// result = (4 - 3), result = (4 - 2), result = (4 - 1)
// 위와 같이 계산하면 최대 이익을 계산할 수 있다.