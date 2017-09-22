#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n, max = -1, min = 1000001;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		if (max < x) {
			max = x;
		}
		if (min > x) {
			min = x;
		}
	}
	printf("%d\n", max * min);
}