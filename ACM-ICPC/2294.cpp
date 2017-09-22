#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int coin[101] = { 0 }, cache[10001] = { 0 };

int main() {
	int n = 0, k = 0;

	scanf("%d %d", &n, &k);

	memset(cache, -1, sizeof(int) * 10001);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	cache[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (cache[j] == -1) {
				cache[j] = cache[j - coin[i]] + 1;
			}
			else {
				cache[j] = min(cache[j], cache[j - coin[i]] + 1);
			}
		}
	}

	printf("%d\n", cache[k]);
}