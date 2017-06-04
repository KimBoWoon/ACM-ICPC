#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[51], b[51];

int main() {
	int n, sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, a + n, less<int>());
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	printf("%d\n", sum);
}