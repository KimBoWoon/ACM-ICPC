#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int card[500001];

int search(int start, int end, int count, int target) {
	int mid = (start + end) / 2;
	int result = 0;

	if (start > end) {
		return count;
	} else {
		if (card[mid] > target) {
			result = search(start, mid - 1, count, target);
		} else if (card[mid] < target) {
			result = search(mid + 1, end, count, target);
		} else {
			result += search(start, mid - 1, count, target);
			result += search(mid + 1, end, count, target);
			result += 1;
		}

		return result;
	}
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
		printf("%d ", search(0, n - 1, 0, x));
	}
	printf("\n");
}