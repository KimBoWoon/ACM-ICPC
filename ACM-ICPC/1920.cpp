#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, q;
int arr[100001];

int comp(const void* x, const void* y) {
	if (*(int*)x < *(int*)y) {
		return -1;
	} else if (*(int*)x > *(int*)y) {
		return 1;
	} else {
		return 0;
	}
}

bool rbinary(int s, int e, int target) {
	int mid = (s + e) / 2;

	while (s <= e) {
		if (arr[mid] == target) {
			return true;
		} else if (arr[mid] > target) {
			return rbinary(s, mid - 1, target);
		} else if (arr[mid] < target) {
			return rbinary(mid + 1, e, target);
		}
	}

	return false;
}

bool binary(int s, int e, int target) {
	while (s <= e) {
		int mid = (s + e) / 2;

		if (arr[mid] == target) {
			return true;
		} else if (arr[mid] > target) {
			e = mid - 1;
		} else if (arr[mid] < target) {
			s = mid + 1;
		}
	}

	return false;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	// sort(q, q + n);
	qsort(arr, n, sizeof(int), comp);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &q);

		if (binary(0, n - 1, q))
			printf("1\n");
		else
			printf("0\n");
	}
}