#define LOCAL

#include <cstdio>
#include <algorithm>
using namespace std;

int n, x, cnt, ansCnt;
long long ans;
long long arr[1000001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + n);

	cnt = 1;

	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (cnt > ansCnt) {
			ansCnt = cnt;
			ans = arr[i];
		}
	}

	printf("%lld\n", ans);
}