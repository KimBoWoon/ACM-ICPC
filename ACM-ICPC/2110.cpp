#include <cstdio>
#include <algorithm>
using namespace std;

int x[200000];
int n, c;

int main() {
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	sort(x, x + n);

	int start = 1, end = x[n - 1] - x[0], cnt, h, ans;
	int mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 1;
		h = x[0];
		
		for (int i = 1; i < n && cnt <= c; i++) {
			if (x[i] - h >= mid) {
				cnt++;
				h = x[i];
			}
		}

		if (cnt >= c) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}

	printf("%d\n", ans);
}