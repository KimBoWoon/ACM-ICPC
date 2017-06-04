#include <cstdio>
#include <cstdlib>

#pragma warning(disable:4996)

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int n;
		int arr[100] = { 0 };

		scanf("%d", &n);

		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;

		for (int i = 4; i <= n; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

		printf("%d\n", arr[n]);
	}
}