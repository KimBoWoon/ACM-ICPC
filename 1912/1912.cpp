#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[100001], d[100001];
int n;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		d[i] = max(arr[i], arr[i] + d[i - 1]);
	}

	int sum = d[1];
	for (int i = 2; i <= n; i++) {
		if (d[i] > sum) {
			sum = d[i];
		}
	}

	printf("%d\n", sum);

	return 0;
}