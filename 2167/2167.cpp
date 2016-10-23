#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[301][301];
int n, m, k;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d", &k);

	while (k--) {
		int i, j, x, y, sum = 0;

		scanf("%d %d %d %d", &i, &j, &x, &y);

		for (int a = i; a <= x; a++) {
			for (int b = j; b <= y; b++) {
				sum += arr[a][b];
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}