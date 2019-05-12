#include <bits/stdc++.h>

int arr[501][501], d[501][501];
int n, answer = -1;

int topDown(int x, int y) {
	if (x == 1 && y == 1) {
		return arr[1][1];
	}
	if (arr[x][y] == -1) {
		return 0;
	}
	if (d[x][y] != 0) {
		return d[x][y];
	}

	return d[x][y] = std::max(topDown(x - 1, y), topDown(x - 1, y - 1)) + arr[x][y];
}

int bottomUp(int x) {
	d[1][1] = arr[1][1];
	for (int i = 2; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				d[i][j] = d[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				d[i][j] = d[i - 1][j - 1] + arr[i][j];
			}
			else {
				d[i][j] = std::max(d[i - 1][j] + arr[i][j], d[i - 1][j - 1] + arr[i][j]);
			}
		}
	}

	for (int i = 1; i <= x; i++) {
		if (d[x][i] > answer) {
			answer = d[n][i];
		}
	}

	return answer;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			arr[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(d, 0, sizeof(int) * 501 * 501);

	for (int i = 1; i <= n; i++) {
		int temp = topDown(n, i);
		if (temp > answer) {
			answer = temp;
		}
	}

	printf("%d\n", answer);
	// printf("%d\n", bottomUp(n));

	return 0;
}