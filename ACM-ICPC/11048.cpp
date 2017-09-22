#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int n, m;
int arr[1001][1001], d[1001][1001];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	d[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = arr[i][j] + max(d[i - 1][j - 1], max(d[i - 1][j], d[i][j - 1]));
		}
	}

	printf("%d\n", d[n][m]);
}