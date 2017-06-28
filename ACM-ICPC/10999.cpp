//
// Created by secret on 6/25/17.
//

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define MAX_SIZE 4000010

typedef long long LLONG;

int n, m, k, a, b, c, d;
LLONG tree[MAX_SIZE], lazy[MAX_SIZE], arr[MAX_SIZE];
// vector<LLONG> tree, lazy, arr;

LLONG init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update_range(int node, int start, int end, int left, int right, LLONG diff) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		return;
	}

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	update_range(node * 2, start, (start + end) / 2, left, right, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

LLONG sum(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) +
		sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1)) - 1;

	//tree.resize(MAX_SIZE);
	//arr.resize(MAX_SIZE);
	//lazy.resize(MAX_SIZE);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		scanf("%d", &a);

		if (a == 1) {
			int start, end;
			LLONG v;

			scanf("%d %d %lld", &start, &end, &v);

			update_range(1, 0, n - 1, start - 1, end - 1, v);
		}
		else if (a == 2) {
			int start, end;

			scanf("%d %d", &start, &end);
			printf("%lld\n", sum(1, 0, n - 1, start - 1, end - 1));
		}
	}
	return 0;
}