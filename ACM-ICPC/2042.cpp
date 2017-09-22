//
// Created by secret on 6/24/17.
//

//#include<stdio.h>
//
//typedef unsigned long long ULLONG;
//ULLONG bit[1000001], a[1000001];
//int n, m, k;
//ULLONG x, y, z;
//
//void update(int h, ULLONG x) {
//    for (int i = h; i <= n; i += i & -i) {
//        bit[i] += x;
//    }
//}
//
//ULLONG query(int h) {
//    ULLONG r = 0;
//
//    for (int i = h; i; i -= i & -i) {
//        r += bit[i];
//    }
//
//    return r;
//}
//
//int main() {
//    scanf("%d %d %d", &n, &m, &k);
//
//    for (int i = 1; i <= n; i++) {
//        scanf("%lld", &a[i]);
//        update(i, a[i]);
//    }
//
//    for (int i = 0; i < m + k; i++) {
//        scanf("%lld %lld %lld", &x, &y, &z);
//
//        if (x == 1) {
//            update(y, z - a[y]);
//            a[y] = z;
//        } else {
//            printf("%lld\n", query(z) - query(y - 1));
//        }
//    }
//
//    return 0;
//}

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LLONG;
int n, m, k, h, tree_size;
LLONG tree[4000010], arr[4000010];
// vector<LLONG> tree, arr;

LLONG init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, LLONG diff) {
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

LLONG sum(int node, int start, int end, int left, int right) {
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
	scanf("%d %d %d", &n, &m, &k);

	// h = (int) ceil(log2(n));
	// tree_size = (1 << (h + 1));

	// tree.resize(tree_size + 1);
	// arr.resize(n + 1);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a;

		scanf("%d", &a);

		if (a == 1) {
			int b;
			LLONG c;
			scanf("%d %lld", &b, &c);
			update(1, 0, n - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 0, n - 1, b - 1, c - 1));
		}

		//        for (int k = 0; k < n; k++) {
		//            printf("%lld ", arr[k]);
		//        }
		//        printf("\n");
		//        for (int k = 1; k <= tree_size; k++) {
		//            printf("%lld ", tree[k]);
		//        }
		//        printf("\n");
	}
}