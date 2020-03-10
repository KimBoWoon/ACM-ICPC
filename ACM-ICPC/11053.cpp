#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2e9

int n, x;
vector<int> v;

// 이분탐색을 시작하여 최적의 위치 탐색
// lower_bound(start, end, target)을 사용
// target보다 큰 가장 작은 정수를 찾아 교체한다

int main() {
    scanf("%d", &n);

    v.push_back(INF);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (v.back() < x) {
            v.push_back(x);
        } else {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }

    printf("%d\n", v.size());
}

// int a[1010], ans[1010];
// int n, x;

// int main() {
//     scanf("%d", &n);

//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &a[i]);
//     }

//     for (int i = 1; i <= n; i++) {
//         int min = 0;
//         for (int j = 0; j < i; j++) {
//             if (a[i] > a[j]) {
//                 if (min < ans[j]) {
//                     min = ans[j];
//                 }
//             }
//         }
//         ans[i] = min + 1;
//         if (max < ans[i])
//             max = ans[i];
//     }

//     printf("%d\n", max);
// }