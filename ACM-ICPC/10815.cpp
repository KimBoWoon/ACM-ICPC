#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define SIZE 500001

int a[SIZE];

int main() {
	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int target;

		scanf("%d", &target);

		if (binary_search(a, a + n, target)) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}