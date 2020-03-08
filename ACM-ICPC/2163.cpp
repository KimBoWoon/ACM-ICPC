#include <cstdio>

#pragma warning(disable:4996)

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d\n", n * m - 1);
}

// n * m 초콜릿을 1 * m 으로 나누기 위해 자르는 횟수 n - 1
// 1 * m 초콜릿을 1 * 1 으로 나누기 위해 자르는 횟수 m - 1
// (n - 1) + n * (m - 1)
// n - 1 + n * m - n
// n * m - 1