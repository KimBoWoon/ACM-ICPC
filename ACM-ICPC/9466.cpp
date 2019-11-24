#include <cstdio>
#include <memory.h>
using namespace std;

int t, n, cnt;
int arr[100001];
bool mark[100001], check[100001];

void dfs(int v) {
	mark[v] = true;
    if (!mark[arr[v]]) {
        dfs(arr[v]);
    } else if (!check[arr[v]]) {
        for (int i = arr[v]; i != v; i = arr[i]) {
            cnt++;
        }
        cnt++;
    }

    check[v] = true;
}

int main() {
    scanf("%d", &t);

    while (t--) {
        cnt = 0;
        memset(check, 0, 100001);
        memset(mark, 0, 100001);

        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (!mark[i]) {
                dfs(i);
            }
        }

        printf("%d\n", n - cnt);
    }
}