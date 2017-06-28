#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_SIZE 400001
#define INF 1000000001

int n, m, a, b;
int tree[MAX_SIZE][2], arr[MAX_SIZE];

int minInit(int node, int start, int end) {
	if (start == end) {
		return tree[node][0] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node][0] = min(minInit(node * 2, start, mid), minInit(node * 2 + 1, mid + 1, end));
}

int maxInit(int node, int start, int end) {
	if (start == end) {
		return tree[node][1] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node][1] = max(maxInit(node * 2, start, mid), maxInit(node * 2 + 1, mid + 1, end));
}

int minQuery(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INF;
	}

	if (left <= start && end <= right) {
		return tree[node][0];
	}

	int mid = (start + end) / 2;

	return min(minQuery(node * 2, start, mid, left, right), minQuery(node * 2 + 1, mid + 1, end, left, right));
}

int maxQuery(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return -1;
	}

	if (left <= start && end <= right) {
		return tree[node][1];
	}

	int mid = (start + end) / 2;

	return max(maxQuery(node * 2, start, mid, left, right), maxQuery(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	minInit(1, 0, n - 1);
	maxInit(1, 0, n - 1);

	while (m--) {
		scanf("%d %d", &a, &b);

		printf("%d %d\n", minQuery(1, 0, n - 1, a - 1, b - 1), maxQuery(1, 0, n - 1, a - 1, b - 1));
	}
}