#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int arr[501][501], d[501][501];
int n, big = -1;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(d, 0, sizeof(int) * 501 * 501);

	d[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				d[i][j] = d[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				d[i][j] = d[i - 1][j - 1] + arr[i][j];
			}
			else {
				d[i][j] = max(d[i - 1][j] + arr[i][j], d[i - 1][j - 1] + arr[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[n][i] > big) {
			big = d[n][i];
		}
	}

	printf("%d\n", big);

	return 0;
}