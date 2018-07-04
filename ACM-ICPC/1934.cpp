#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	if (!b) {
		return a;
	}
	gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int testCase;

	scanf("%d", &testCase);

	while (testCase--) {
		int a, b;

		scanf("%d %d", &a, &b);

		printf("%d\n", lcm(a, b));
	}
}