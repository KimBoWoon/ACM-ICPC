#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int x, n;
int lego[1000001];

bool rBinarySearch(int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;

        if (lego[mid] == target) {
            return true;
        } else if (lego[mid] > target) {
            return rBinarySearch(start, mid - 1, target);
        } else if (lego[mid] < target) {
            return rBinarySearch(mid + 1, end, target);
        }
    }

    return false;
}

bool binarySearch(int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;

        if (lego[mid] == target) {
            return true;
        } else if (lego[mid] > target) {
            end = mid - 1;
        } else if (lego[mid] < target) {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    while (scanf("%d", &x) == 1) {
        scanf("%d", &n);

        x *= 10000000;

        for (int i = 0; i < n; i++) {
            scanf("%d", &lego[i]);
        }

        sort(lego, lego + n);

        // 하나의 값을 선택하고 필요한 길이에서 뺀 뒤 나머지길이를 이분 탐색 한다
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            int cur = lego[i];

            if (binarySearch(i + 1, n, x - cur)) {
                printf("yes %d %d\n", cur, x - cur);
                flag = true;
                break;
            }
        }
        if (!flag) {
            printf("danger\n");
        }
        memset(lego, 0, sizeof(int) * 1000001);
    }
}