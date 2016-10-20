#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int arr[10001];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[x - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i + 1);
		}
	}

	return 0;
}