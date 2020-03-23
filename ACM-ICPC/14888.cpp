#include <cstdio>
#include <climits>
#include <utility>
using namespace std;

int n;
int arr[101], op[4];
pair<int, int> answer;

// dfs를 사용하여 모든 값을 확인한다
void dfs(int result, int idx, int a, int b, int c, int d) {
    if (a > 0) {
        dfs(result + arr[idx], idx + 1, a - 1, b, c, d);
    }
    if (b > 0) {
        dfs(result - arr[idx], idx + 1, a, b - 1, c, d);
    }
    if (c > 0) {
        dfs(result * arr[idx], idx + 1, a, b, c - 1, d);
    }
    if (d > 0) {
        dfs(result / arr[idx], idx + 1, a, b, c, d - 1);
    }
    
    if (idx == n) { // 모든 연산자를 사용했을 경우 값 확인
        if (result > answer.second) {
            answer.second = result;
        }
        if (result < answer.first) {
            answer.first = result;
        }
        return;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);

    answer.first = INT_MAX;
    answer.second = INT_MIN;

    dfs(arr[0], 1, op[0], op[1], op[2], op[3]);

    printf("%d\n%d\n", answer.second, answer.first);
}