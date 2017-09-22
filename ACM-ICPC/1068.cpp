#include <cstdio>

int n, r, d, par[55], cnt;

void dfs(int ix) {
	int i = n, fl = 1;

	if (ix == d) {
		return;
	}

	while (i--) {
		if (par[i] == ix && i != d) {
			dfs(i), fl = 0;
		}
	}

	cnt += fl;
}

int main() {
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &par[i]);
		if (par[i] < 0) {
			r = i;
		}
	}

	scanf("%d", &d);

	dfs(r);

	printf("%d", cnt);

	return 0;
}