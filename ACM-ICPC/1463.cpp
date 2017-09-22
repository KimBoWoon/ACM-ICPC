#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[1000001];

int main() {
	int n = 0, cnt = 0;

	scanf("%d", &n);

	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}

	printf("%d\n", arr[n]);
}