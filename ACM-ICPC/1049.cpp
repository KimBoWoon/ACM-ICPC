#include <cstdio>
using namespace std;

int n, m, mina = 999999999, minb = 999999999;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		if (mina > a) {
			mina = a;
		}
		if (minb > b) {
			minb = b;
		}
	}

	if (mina > 6 * minb) {
		mina = 6 * minb;
	}
	if ((n % 6) * minb > mina) {
		printf("%d\n", (n / 6) * mina + mina);
	}
	else {
		printf("%d\n", (n / 6) * mina + (n % 6) * minb);
	}
}