#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[2][100001], d[2][100001];
int t, n;

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			// max(¿· ½ºÆ¼Ä¿¸¦ ¶«, ´ë°¢¼± ½ºÆ¼Ä¿¸¦ ¶«);
			d[0][i] = max(d[0][i - 1], d[1][i - 1] + arr[0][i]);
			d[1][i] = max(d[1][i - 1], d[0][i - 1] + arr[1][i]);
		}

		printf("%d\n", max(d[0][n - 1], d[1][n - 1]));
	}

	return 0;
}