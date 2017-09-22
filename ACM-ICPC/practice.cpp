//
// Created by secret on 6/24/17.
//

#include <cstdio>
#include <cmath>

int n;
int tree[1000001], arr[1000001] = {3, 5, 6, 7, 2, 9, 4, 5, 2, 8, 1, 5};

int init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, int diff) {
    if (!(start <= index && index <= end)) {
        return;
    }

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;

        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    n = 12;
    int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));

    init(1, 0, n - 1);
    update(1, 0, n - 1, 4, 10 - arr[4]);
    printf("%d\n", sum(1, 0, n - 1, 8, 11));

    for (int i = 1; i <= tree_size; i++) {
        printf("%d ", tree[i]);
    }
}