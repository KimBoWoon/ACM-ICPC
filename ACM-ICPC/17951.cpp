#include <cstdio>
#include <cmath>
using namespace std;

int n, k, x, answer = 2e9;
int arr[100001];

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        
    }
    // for (int i = 1; i <= n; i++) {
    //     scanf("%d", &x);
    //     arr[i] = arr[i - 1] + x;
    // }

    // for (int i = 0; i < k; i++) {
    //     if (answer > abs(arr[n / k * i] - arr[(n / k) * (i + 1)])) {
    //         answer = abs(arr[n / k * i] - arr[(n / k) * (i + 1)]);
    //     }
    // }

    // printf("%d\n", answer);
}