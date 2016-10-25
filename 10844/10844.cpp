#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[101][101];

int main() {
	int n;

	scanf("%d", &n);

	arr[0][1] = 0;
	for (int i = 1; i <= 9; i++) {
		arr[i][1] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 9; j++) {
			arr[j][i] = arr[j - 1][i - 1] + arr[j + 1][i - 1];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}

	return 0;
}