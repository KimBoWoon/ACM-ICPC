#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
long long answer;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer += abs(arr[i] - arr[j]);
        }
    }

    printf("%lld\n", answer);
}