#include <cstdio>
#include <algorithm>
using namespace std;

int a[10], sum = 0;

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 && j != i; j++) {
			sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum += a[k];
				}
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d\n", a[k]);
					}
				}
				return 0;
			}
		}
	}
}