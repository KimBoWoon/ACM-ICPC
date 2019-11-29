#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 1000000

int n, m, k, h, x, tree_size;
vector<int> tree[SIZE * 2];

void update(int node, int start, int end, int index, int value) {
    if (start > index || index > end) {
        return;
    }

    tree[node].push_back(value);

    if (start != end) {
        int mid = (start + end) / 2;

        update(node * 2, start, mid, index, value);
        update(node * 2 + 1, mid + 1, end, index, value);
    }
}

int get(int node, int start, int end, int left, int right, int value) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
    }

    int mid = (start + end) / 2;

    return get(node * 2, start, mid, left, right, value) + get(node * 2 + 1, mid + 1, end, left, right, value);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        update(1, 1, n, i, x);
    }

    for (int i = 0; i < SIZE * 2; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;

        scanf("%d %d %d", &x, &y, &z);
        int l = -1e9, r = 1e9;
		int mid = (l + r) / 2;
		while(l <= r) {
			mid = (l + r) / 2;
			if(get(1, 1, n, x, y, mid) < z) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
		}
        printf("%d\n", l);
    }
}