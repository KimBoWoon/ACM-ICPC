#include <stdio.h>

int main() {
	int testCase;

	scanf("%d", &testCase);

	while (testCase--) {
		int i, a, b;
		int result = 1;

		scanf("%d %d", &a, &b);

		for (i = 0; i < b; i++)
			result = result * a % 10;

		if (result == 0)
			printf("10\n");
		else
			printf("%d\n", result);
	}
}