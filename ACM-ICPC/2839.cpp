#include <cstdio>
using namespace std;

int n, min = 99999999;

/*
3kg, 5kg의 설탕 봉지를 가지고 모든 경우의 수를 탐색
*/

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i * 3) + (j * 5) == n && i + j < min) {
				min = i + j;
			}
		}
	}

	if (min != 99999999) {
		printf("%d\n", min);
	}
	else {
		printf("-1\n");
	}
}