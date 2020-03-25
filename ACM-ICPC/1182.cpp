#include <cstdio>
using namespace std;

int n, s, answer;
int arr[21];

void dfs(int i, int sum) {
    if (i == n) {
        return;
    }

    if (sum + arr[i] == s)  {
        answer++;
    }

    dfs(i + 1, sum); // i번을 선택하지 않았을 때
    dfs(i + 1, sum + arr[i]); // i번을 선택했을 때
}

int main() {
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    dfs(0, 0);

    printf("%d\n", answer);
}