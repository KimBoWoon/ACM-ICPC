#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans, x;
int a[1000001];

int main() {
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);

		int p = lower_bound(a, a + ans, x) - a;

		ans += p == ans;
		a[p] = x;
	}

	printf("%d", ans);

	return 0;
}