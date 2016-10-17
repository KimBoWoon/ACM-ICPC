#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[301], d[301];
int n;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		// max(전 계단을 밟지 않음, 전 계단을 밟음);
		d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]);
	}

	printf("%d\n", d[n - 1]);

	return 0;
}