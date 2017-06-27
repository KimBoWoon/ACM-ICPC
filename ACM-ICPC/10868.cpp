#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100001
#define INF 1000000001

int n, m, a, b;
int tree[MAX_SIZE], arr[MAX_SIZE];

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INF;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	init(1, 0, n - 1);

	while (m--) {
		scanf("%d %d", &a, &b);

		printf("%d\n", query(1, 0, n - 1, a - 1, b - 1));
	}
}