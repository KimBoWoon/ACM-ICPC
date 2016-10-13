#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int wine[10001], result[10001][3];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &wine[i]);
	}

	result[0][1] = wine[0];
	for (int i = 1; i < n; i++) {
		result[i][0] = max(result[i - 1][0], max(result[i - 1][1], result[i - 1][2]));
		result[i][1] = wine[i] + result[i - 1][0];
		result[i][2] = wine[i] + result[i - 1][1];
	}

	printf("%d\n", max(result[n - 1][0], max(result[n - 1][1], result[n - 1][2])));

	return 0;
}