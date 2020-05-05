#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int n, k;
int d[1001][1001];

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
			}
		}
	}

	printf("%d\n", d[n][k]);
}

// 파스칼의 삼각형
// https://namu.wiki/w/%ED%8C%8C%EC%8A%A4%EC%B9%BC%EC%9D%98%20%EC%82%BC%EA%B0%81%ED%98%95