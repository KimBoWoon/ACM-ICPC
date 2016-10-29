#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int t;
long long a, b, result1, result2;
char op, dummy;

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%lld %c %lld %c %lld", &a, &op, &b, &dummy, &result1);

		switch (op) {
		case '+':
			result2 = a + b;
			break;
		case '-':
			result2 = a - b;
			break;
		case '*':
			result2 = a * b;
			break;
		case '/':
			result2 = a / b;
			break;
		default:
			break;
		}

		if (result1 == result2) {
			printf("correct\n");
		}
		else {
			printf("wrong answer\n");
		}
	}

	return 0;
}