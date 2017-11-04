#define LOCAL

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned long long ULLONG;

ULLONG n, m;
ULLONG arr[1000001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%lld %lld", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // sort for use binary search
    sort(arr, arr + n);

    ULLONG h = 0, start = 0, end = arr[n - 1];

    // using binary search to find median
    while (start + 1 < end) {
        ULLONG sum = 0;
        h = (start + end) / 2;

        // cut the tree
        for (int i = 0; i < n; i++) {
            if (arr[i] > h) {
                sum += arr[i] - h;
            }
        }

        // find target(m)
        if (sum == m) {
            start = h;
            break;
        } else if (sum > m) {
            start = h;
        } else {
            end = h;
        }
    }

    printf("%lld\n", start);
}