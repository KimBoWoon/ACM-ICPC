#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n, m;
	int arr[10001] = { 0 };
	int max = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	scanf("%d", &m);

	int mid = 0, start = 0, end = max;

	while (start <= end) {
		int sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				sum += mid;
			else
				sum += arr[i];
		}

		if (sum > m) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	printf("%d\n", end);
}