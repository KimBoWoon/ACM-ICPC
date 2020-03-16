#include <cstdio>
#include <cmath>
using namespace std;

int n, cnt, tmp;
char data[100];
char ctmp;

void f(int n, int stick1, int stick2, int stick3) {
	if (n == 1) {
		printf("%d %d\n", stick1, stick3);
	}
	else {
		// 1. n - 1개의 원판을 3번 막대를 이용해 2번으로 이동
		f(n - 1, stick1, stick3, stick2);
		// 2. 마지막 원판을 3번 막대로 이동
		printf("%d %d\n", stick1, stick3);
		// 3. 2번 막대에 있는 원판을 1번 막대를 사용하여 3번으로 이동
		f(n - 1, stick2, stick1, stick3);
	}
}

int main() {
	scanf("%d", &n);

	// 2^n-1 계산
	data[0] = '1';
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = cnt; j >= 0; j--) {
			tmp += (data[j] - '0') * 2;
			data[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		if (tmp > 0) {
			ctmp = tmp + '0';
			cnt++;
			for (int j = cnt; j >= 1; j--) {
				data[j] = data[j - 1];
			}
			data[0] = ctmp;
		}
	}
	data[cnt]--;

	printf("%s\n", data);
	if (n <= 20) {
		f(n, 1, 2, 3);
	}

	return 0;
}