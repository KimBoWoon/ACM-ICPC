#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define MAX_PRIME 1000

int arr[1001];
int n, cnt;

/*
소수 찾기
*/

int main() {
	scanf("%d", &n);

	for (int i = 2; i <= MAX_PRIME; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(MAX_PRIME); i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i + i; j <= MAX_PRIME; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		int target;

		scanf("%d", &target);

		if (find(arr, arr + MAX_PRIME, target) != arr + MAX_PRIME) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}