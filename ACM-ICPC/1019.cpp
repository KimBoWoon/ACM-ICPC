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
	scanf("%lld", &end);

	start = mul = 1;
	while (start <= end) {
		// 시작 숫자의 일의 자리를 0으로 맞춘다
		// 맞추면서 사용한 숫자는 체크
		while (start % 10 != 0 && start <= end) {
			calc(start, mul);
			start++;
		}

		// 맞추다가 end까지 왔을 경우
		if (start > end) {
			break;
		}

		// 끝 숫자의 일의 자리를 9으로 맞춘다
		// 맞추면서 사용한 숫자는 체크
		while (end % 10 != 9 && start <= end) {
			calc(end, mul);
			end--;
		}

		// start와 end 사이에 몇 번 사용되는지 파악
		cnt = end / 10 - start / 10 + 1;

		for (int i = 0; i < 10; i++) {
			page[i] += cnt * mul;
		}

		start /= 10;
		end /= 10;
		mul *= 10LL;
	}

	for (int i = 0; i < 10; i++) {
		printf("%lld ", page[i]);
	}
	printf("\n");
}