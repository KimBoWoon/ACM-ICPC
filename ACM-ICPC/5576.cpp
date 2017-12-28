#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int w[10], k[10];

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &w[i]);
	}

	for (int i = 0; i < 10; i++) {
		scanf("%d", &k[i]);
	}

	sort(w, w + 10, greater<int>());
	sort(k, k + 10, greater<int>());

	printf("%d %d\n", w[0] + w[1] + w[2], k[0] + k[1] + k[2]);
}