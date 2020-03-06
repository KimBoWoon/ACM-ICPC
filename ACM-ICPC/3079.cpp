#include <cstdio>
#include <climits>
using namespace std;

typedef unsigned long long ULLONG;

int n, m;
ULLONG desk[100001];
ULLONG maxTime;

ULLONG binarySearch(ULLONG left, ULLONG right) {
    while (left <= right) {
        ULLONG mid = (left + right) / 2, sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mid / desk[i];
        }

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
        scanf("%lld", &desk[i]);
        if (maxTime < desk[i]) {
            maxTime = desk[i];
        }
    }

    printf("%lld\n", binarySearch(1, maxTime * m));
}