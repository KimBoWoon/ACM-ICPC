#include <cstdio>
using namespace std;

int a, b, c, d, s, t;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	s = a + b + c + d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	t = a + b + c + d;

	printf("%d\n", (s < t) ? t : s);
}