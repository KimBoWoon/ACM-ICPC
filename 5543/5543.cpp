#include <cstdio>
using namespace std;

int main() {
	int burgar[3], juice[2];
	int minCost = 9999999;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &burgar[i]);
	}

	for (int i = 0; i < 2; i++) {
		scanf("%d", &juice[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (minCost > burgar[i] + juice[j] - 50) {
				minCost = burgar[i] + juice[j] - 50;
			}
		}
	}

	printf("%d\n", minCost);
}