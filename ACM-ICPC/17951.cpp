#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, high, answer = -1;
int arr[100001];

void parametric(int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum >= mid) {
                cnt++;
                sum = 0;
            }
        }

        // cnt가 k이상이 되면 k개의 그룹으로 나눌수 있다
        // 그러므로 받을 수 있는 점수의 최대는 mid + 1이 된다
        if (cnt >= k) {
            start = mid + 1;
            answer = mid;
        } else {
            // k개의 그룹으로 나눌수 없는 경우이므로
            // end 점수는 받을 수 없다
            // 그러므로 end 값을 mid - 1로 대체
            end = mid - 1;
        }
    }

    printf("%d\n", answer);
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        high += arr[i];
    }

    parametric(0, high);
}

// 파라메트릭 서치를 사용하면 풀리는 문제