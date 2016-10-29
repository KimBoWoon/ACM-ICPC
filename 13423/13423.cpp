#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int n, result = 0;
		int arr[1001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((arr[i] + arr[j]) % 2 == 1 || (arr[i] + arr[j]) % 2 == -1) {
					continue;
				}

				int target = (arr[i] + arr[j]) / 2;
				
				if (binary_search(arr, arr + n, target)) {
					result++;
				}
			}
		}
		printf("%d\n", result);
	}

	return 0;
}