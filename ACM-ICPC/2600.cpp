#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int b[3], k1[5], k2[5], arr[501][501];

int main() {
	scanf("%d %d %d", &b[0], &b[1], &b[2]);

	for (int i = 0; i < 5; i++) {
		scanf("%d %d", &k1[i], &k2[i]);
	}

	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			arr[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				if (i - b[k] >= 0 && arr[i - b[k]][j] == 0) {
					arr[i][j] = 1;
				}
				if (j - b[k] >= 0 && arr[i][j - b[k]] == 0) {
					arr[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%c\n", (arr[k1[i]][k2[i]] == 1) ? 'A' : 'B');
	}
}