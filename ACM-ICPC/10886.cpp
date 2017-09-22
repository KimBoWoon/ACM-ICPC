#include <cstdio>

int n, cnt1, cnt2;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		if (x == 0) {
			cnt1++;
		}
		else {
			cnt2++;
		}
	}

	printf("%s\n", (cnt1 > cnt2) ? "Junhee is not cute!" : "Junhee is cute!");
}