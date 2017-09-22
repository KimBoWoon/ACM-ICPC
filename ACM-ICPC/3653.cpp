#include <cstdio>

#define MAX_SIZE 400001
int t, n, m;
int tree[MAX_SIZE], arr[MAX_SIZE];

void update(int h) {
	for (; h <= n + m; h += h & -h) {
		tree[h]++;
	}
}

int query(int h) {
	int s = 0;

	for (; h; h -= h & -h) {
		s += tree[h];
	}

	return s;
}

int main() {
	scanf("%d", &t);

	while (t--) {
		int i = 1, x;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n + m; i++) {
			tree[i] = 0;
		}

		for (; i <= n; i++) {
			arr[i] = n + 1 - i;
		}

		for (; i <= n + m; i++) {
			scanf("%d", &x);
			printf("%d ", i - arr[x] - 1 - query(i) + query(arr[x]));
			update(arr[x]);
			arr[x] = i;
		}
		printf("\n");
	}
}