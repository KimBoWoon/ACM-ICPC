#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

#define MAX_COST 999999999

int arr[101][101], c[101][101];

void Floyd(int arr[101][101], int start, int end) {
	for (int k = 1; k <= end; k++) {
		for (int i = 1; i <= end; i++) {
			for (int j = 1; j <= end; j++) {
				if (c[i][j] > c[i][k] + c[k][j]) {
					c[i][j] = c[i][k] + c[k][j];
				}
			}
		}
	}
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int x = 0; x < 101; x++) {
		for (int y = 0; y < 101; y++) {
			if (x - y) {
				arr[x][y] = MAX_COST;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		if (arr[x][y] > c) {
			arr[x][y] = c;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[i][j] = arr[i][j];
		}
	}

	Floyd(arr, 1, n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (c[i][j] == MAX_COST) {
				printf("0 ");
			}
			else {
				printf("%d ", c[i][j]);
			}
		}
		printf("\n");
	}
}