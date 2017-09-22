#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int tc;

	scanf("%d", &tc);

	while (tc--) {
		int n, a, b, c, result = 0, maxA = 0;

		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);

			maxA = max(a, max(b, c));

			if (maxA < 0) {
				continue;
			}

			result += maxA;
		}
		printf("%d\n", result);
	}
	return 0;
}