#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

typedef unsigned long long ULLONG;

int main() {
	ULLONG n, m;
	ULLONG *arr;

	scanf("%lld %lld", &n, &m);

	arr = (ULLONG*)calloc(n, sizeof(ULLONG));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	ULLONG h = 0, start = 0, end = arr[n - 1];

	while (start + 1 < end) {
		ULLONG sum = 0;
		h = (start + end) / 2;

		for (int i = 0; i < n; i++) {
			if (arr[i] > h) {
				sum += arr[i] - h;
			}
		}

		if (sum >= m) {
			start = h;
		}
		else {
			end = h;
		}
	}

	printf("%d\n", start);
}