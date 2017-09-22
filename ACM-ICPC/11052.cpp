#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int n;
int arr[10001], d[10001];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	d[1] = arr[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + arr[j]);
		}
	}

	printf("%d\n", d[n]);

	return 0;
}