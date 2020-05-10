#include <cstdio>
using namespace std;

int n, m, minA = 999999999, minB = 999999999;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		if (minA > a) { // 세트로 샀을 때 가장 작은 값
			minA = a;
		}

		if (minB > b) { // 낱개로 샀을 때 가장 작은 값
			minB = b;
		}
	}

	if (minA > 6 * minB) { // 만약 낱개로 6개를 사도 세트보다 싼 경우
		minA = 6 * minB;
	}

	if ((n % 6) * minB > minA) { // 낱개를 구입 가격이 세트가격보다 비싸지면
		printf("%d\n", (n / 6) * minA + minA); // 한 세트를 더 사는게 좋다
	} else {
		printf("%d\n", (n / 6) * minA + (n % 6) * minB);
	}
}