#include <cstdio>
#include <cstdlib>
#include <cstring>

int dfs(int* arr, int* temp, int i) {
	temp[i] = 1;

	int next = arr[i] - 1;
	if (temp[next] == 0)
		dfs(arr, temp, next);
}
int main() {
	int testCase;

	scanf("%d", &testCase);

	while (testCase--) {
		int size, i, cycle = 0;
		int* arr;
		int* temp;

		scanf("%d", &size);

		arr = (int *)malloc(sizeof(int) * size);
		temp = (int *)malloc(sizeof(int) * size);
		memset(temp, 0, sizeof(temp) * size);

		for (i = 0; i < size; i++)
			scanf("%d", &arr[i]);

		for (int i = 0; i < size; i++) {
			if (temp[i] == 0) {
				cycle++;
				dfs(arr, temp, i);
			}
		}
		printf("%d\n", cycle);
	}
}