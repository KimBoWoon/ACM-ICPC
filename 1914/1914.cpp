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
		f(n - 1, stick1, stick3, stick2);
		printf("%d %d\n", stick1, stick3);
		f(n - 1, stick2, stick1, stick3);
	}
}

int main() {
	scanf("%d", &n);

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