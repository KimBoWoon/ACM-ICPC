#include <iostream>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;

int mergeMatrix[501][501] = { 0 };
int file[501] = { 0 };
int sum[501] = { 0 };

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int size;

		cin >> size;

		memset(file, 0, sizeof(int) * 501);
		memset(sum, 0, sizeof(int) * 501);

		for (int i = 0; i < size; i++) {
			cin >> file[i];
			sum[i + 1] = sum[i] + file[i];
		}

		for (int x = 1; x < size; x++) {
			for (int y = 1; y <= size - x; y++) {
				int j = y + x;
				if (j > size)
					break;
				mergeMatrix[y][j] = INT_MAX;
				for (int k = y; k < j; k++)
					mergeMatrix[y][j] = min(mergeMatrix[y][j], mergeMatrix[y][k] + mergeMatrix[k + 1][j] + sum[j] - sum[y - 1]);
			}
		}
		cout << mergeMatrix[1][size] << endl;
	}
	return 0;
}