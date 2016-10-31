#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#pragma warning(disable:4996)

int n, k;
int arr1[100001], arr2[2][100001];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr1[i]);
	}

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &arr2[0][i], &arr2[1][i]);
	}

	int maxA = arr2[0][k - 1], maxD = arr2[1][k - 1];
	for (int i = k - 1; i; i--) {
		sort(arr1 + 1, arr1 + arr2[0][i] + 1, less<int>());
		sort(arr1 + 1, arr1 + arr2[1][i] + 1, greater<int>());
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	return 0;
}