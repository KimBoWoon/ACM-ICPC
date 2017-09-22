#include <cstdio>
using namespace std;

int m, n, sum, min;
bool flag;

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 1; i * i <= n; i++) {
		if (i * i > m) {
			sum += (i * i);
		}
		if (!flag && i * i > m) {
			min = i * i;
			flag = !flag;
		}
	}

	if (sum == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n%d\n", sum, min);
	}
}