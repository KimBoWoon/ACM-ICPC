#include <bits/stdc++.h>
using namespace std;

#define MAX 4001

typedef long long LLONG;

int n;
int a[MAX], b[MAX], c[MAX], d[MAX], ab[MAX * MAX], cd[MAX * MAX];
LLONG answer;

void binarySearch(int left, int right) {
    for (int i = 0; i < n * n; i++) {
        while (left < right) {
            int mid = (left + right) / 2;

            if (ab[i] > cd[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int l = right;

        left = 0, right = n * n;

        while (left < right) {
            int mid = (left + right) / 2;

            if (ab[i] >= cd[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int h = right;

        answer += (LLONG) (h - l);

        left = 0, right = n * n;
    }

    printf("%lld\n", answer);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    // a와 b, c와 d의 모든 경우의 수를 생각하면 n * n이 된다
    // 두 배열을 하나의 배열로 합치면서 각각의 배열의 합을 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[n * i + j] = a[i] + b[j];
            cd[n * i + j] = c[i] + d[j];
        }
    }

    sort(cd, cd + n * n);

    // binarySearch(0, n * n);

    // 한 쪽 배열에서 대응하는 값을 찾아야 한다
    // lower_bound를 사용해 해당값의 첫 위치를
    // upper_bound를 사용해 해당값의 마지막 위치를 찾는다
    // 서로 빼주면 해당 값을 0으로 만들 수 있는 값들의 위치만 나오게 된다
    // -ab[i] : a + b 와 c + d의 합이 0이 되려면 한 쪽은 음수여야 한다
    // -cd : lower_bound와 upper_bound는 해당 위치의 iterator를 반환하므로
    // 시작 위치를 빼주면 해당위치를 구할 수 있다
    for (int i = 0; i < n * n; i++) {
        int low = lower_bound(cd, cd + n * n, -ab[i]) - cd;
        int high = upper_bound(cd, cd + n * n, -ab[i]) - cd;

        answer += high - low;
    }

    printf("%lld\n", answer);
}