#include <cstdio>
#include <cstdlib>

#pragma warning(disable:4996)

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int a, b, x;

		scanf("%d %d", &a, &b);

		while (a)
		{
			x = b / a;
			if (b % a) {
				x++;
			}
			a = a * x - b;
			b *= x;
		}
		printf("%d\n", x);
	}
}