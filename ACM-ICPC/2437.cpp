#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans = 1;
int weight[1001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    sort(weight, weight + n);

    // n개의 추의 무게 < 현재 올릴 무게 이면 사이에 있는 값들은 측정할 수 없다
    for (int i = 0; i < n; i++) {
        if (ans < weight[i]) {
            printf("%d\n", ans);
            return 0;
        }
        ans += weight[i];
    }

    printf("%d\n", ans);
}