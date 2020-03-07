#include <cstdio>
using namespace std;

int n, m;
int arr[301];

bool f(int mid) {
    int sum = 0, group = 1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > mid) {
            sum = arr[i];
            group++;
        }
    }

    return group <= m;
}

int main() {
    int start = 0, end = 30000;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        
        if (arr[i] > start) {
            start = arr[i];
        }
    }

    while (start <= end) {
        int mid = (start + end) / 2;

        if (f(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    printf("%d\n", start);

    int i = 0, sum = 0, group = 0;
    for (; i < n; i++) {
        sum += arr[i];

        if (sum > start) {
            sum = arr[i];
            m--;
            printf("%d ", group);
            group = 0;
        }
        group++;
        if (n - i == m) {
            break;
        }
    }

    while (m--) {
        printf("%d ", group);
        group = 1;
    }
}