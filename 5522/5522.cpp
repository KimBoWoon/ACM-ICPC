#include <cstdio>

#pragma warning(disable:4996)

int main() {
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp;
	}

	printf("%d\n", sum);
}