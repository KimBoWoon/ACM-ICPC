#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n, day;
int tree[100001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    sort(tree, tree + n, greater<int>());

    for (int i = 1; i <= n; i++) {
        if (tree[i - 1] + i > day) {
            day = tree[i - 1] + i;
        }
    }

    printf("%d\n", day + 1);
}