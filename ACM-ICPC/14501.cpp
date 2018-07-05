#include <cstdio>
#include <algorithm>
using namespace std;

int n, result;
int consulting[2][16];
int ans[16];

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &consulting[0][i], &consulting[1][i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + consulting[0][i]; j <= n + 1; j++) {
			ans[j] = max(ans[j], ans[i] + consulting[1][i]);
		}
	}

	printf("%d\n", ans[n + 1]);
}