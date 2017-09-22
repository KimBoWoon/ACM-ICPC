#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans;
int a[40001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int p = lower_bound(a, a + ans, a[i]) - a;

		if (p == ans) {
			ans++;
		}
		a[p] = a[i];
	}

	printf("%d\n", ans);
}