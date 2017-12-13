#include <cstdio>
#include <cmath>

int sum;
bool flag;

int main() {
	for (int i = 0; i < 10; i++) {
		int x;

		scanf("%d", &x);

		if (!flag) {
			if (abs(sum + x - 100) <= abs(sum - 100)) {
				sum += x;
			}
			else {
				flag = true;
			}
		}
	}

	printf("%d\n", sum);
}