#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[1001];

int main() {
	int n;

	scanf("%d", &n);

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	printf("%d\n", arr[n] % 10007);

	return 0;
}