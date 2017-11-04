#include <cstdio>
using namespace std;

typedef unsigned long long ULLONG;
ULLONG start, end, mul, cnt;
ULLONG page[10];

void calc(ULLONG n, ULLONG x) {
	while (n != 0) {
		page[n % 10] += x;
		n /= 10;
	}
}

int main() {
	scanf("%d", &end);

	start = mul = 1;
	while (start <= end) {
		while (start % 10 != 0 && start <= end) {
			calc(start, mul);
			start++;
		}

		if (start > end) {
			break;
		}

		while (end % 10 != 9 && start <= end) {
			calc(end, mul);
			end--;
		}

		cnt = end / 10 - start / 10 + 1;

		for (int i = 0; i < 10; i++) {
			page[i] += cnt * mul;
		}

		start /= 10;
		end /= 10;
		mul *= 10LL;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", page[i]);
	}
	printf("\n");
}