#define LOCAL

#include <cstdio>
#include <cmath>
#include <cstdlib>

int a, b, c, d, p, x, y;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	x = a * p;
	
	if (c < p) {
		y = b + d * (p - c);
	}
	else {
		y = b;
	}

	printf("%d\n", (x > y) ? y : x);
}