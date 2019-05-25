#include <bits/stdc++.h>
using namespace std;

int x[200000];
int n, c, answer;

int binarySearch(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2, cnt = 1, h = x[0];

		for (int i = 1; i < n; i++) {
			if (x[i] - h >= mid) {
				cnt++;
				h = x[i];
			}
		}

		if (cnt >= c) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return answer;
}

int main() {
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	sort(x, x + n);

	printf("%d\n", binarySearch(1, x[n - 1] - x[0]));
}