#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[31];

int main() {
	int n;

	scanf("%d", &n);

	arr[0] = 1;
	arr[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		arr[i] = 3 * arr[i - 2];
		for (int j = 4; j <= i; j += 2) {
			arr[i] += 2 * arr[i - j];
		}
	}

	printf("%d\n", arr[n]);
}