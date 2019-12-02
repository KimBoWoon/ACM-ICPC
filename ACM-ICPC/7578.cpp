#include <cstdio>
using namespace std;

#define SIZE 2000010

int n;
long long a[SIZE], b[SIZE], tree[SIZE];
long long answer;

void update(int node, int index, int start, int end, int diff) {
    if (start > index || index > end) {
        return;
    }

    tree[node] += diff;

    if (start != end) {
        update(node * 2, index, start, (start + end) / 2, diff);
        update(node * 2 + 1, index, (start + end) / 2 + 1, end, diff);
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        b[i] = a[x];
    }

    for (int i = 1; i <= n; i++) {
        answer += query(1, 1, n, b[i] + 1, n);
        update(1, b[i], 1, n, 1);
    }

    printf("%lld\n", answer);
}