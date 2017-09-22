#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[100001];

int main() {
	int n, weight = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	for (int i = n - 1; i >= 0; i--) {
		weight = max(weight, arr[i] * (n - i));
	}

	printf("%d\n", weight);
}