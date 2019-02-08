#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int card[500001];

int search(int start, int end, int target) {
	int mid = (start + end) / 2;
	int count = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (card[mid] == target) {
			for (int i = start; i <= end; i++) {
				if (card[i] == target) {
					count++;
				}
			}

			return count;
		} else if (card[mid] > target) {
			end = mid - 1;
		} else if (card[mid] < target) {
			start = mid + 1;
		}
	}

	return 0;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}

	sort(card, card + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		// printf("%d ", search(0, n - 1, x));
		// printf("%d ", upper_bound(card, card + n, x) - lower_bound(card, card + n, x));
		pair<int*, int*> result = equal_range(card, card + n, x);
		printf("%d ", result.second - result.first);
	}
	printf("\n");
}