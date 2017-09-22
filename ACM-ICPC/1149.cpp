#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[1001][3], cost[1001][3];
int minCost;

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	cost[0][0] = arr[0][0];
	cost[0][1] = arr[0][1];
	cost[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + arr[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + arr[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + arr[i][2];
	}

	minCost = min(cost[n - 1][0], cost[n - 1][1]);
	minCost = min(minCost, cost[n - 1][2]);

	printf("%d\n", minCost);

	return 0;
}