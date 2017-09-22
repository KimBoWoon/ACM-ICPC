#include <cstdio>
using namespace std;

int t, n, rx, ry;
int rank[100001];

int recruit() {
	int min = rank[1], ans = 1;

	for (int i = 1; i <= n; i++) {
		if (min > rank[i]) {
			ans++;
			min = rank[i];
		}
	}
	return ans;
}

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &rx, &ry);
			rank[rx] = ry;
		}

		printf("%d\n", recruit());
	}
}