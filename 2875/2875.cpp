#include <cstdio>
using namespace std;

int n, m, k, ans;

int main() {
	scanf("%d %d %d", &n, &m, &k);

	while (n / 2 && m) {
		n -= 2;
		m--;
		ans++;
	}

	(m > 0) ? k -= m : 0;
	(n > 0) ? k -= n : 0;

	while (k > 0 && ans != 0) {
		ans--;
		k -= 3;
	}

	printf("%d\n", ans);
}