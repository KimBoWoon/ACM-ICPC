#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

#pragma warning(disable:4996)

int n;
map<int, int> m;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		m[x]++;
	}

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		printf("%d ", m[x]);
	}
	printf("\n");
}