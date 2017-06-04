#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

#pragma warning(disable:4996)

typedef unsigned long long ULLONG;

int main() {
	int k, n;
	ULLONG arr[10001] = { 0 };

	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++)
		scanf("%lld", &arr[i]);

	ULLONG mid = 0, start = 0, end = LLONG_MAX;

	while (start + 1 < end) {
		ULLONG sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < k; i++) {
			sum += arr[i] / mid;
		}

		if (sum >= n) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	printf("%lld\n", start);
}