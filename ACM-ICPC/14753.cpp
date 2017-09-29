#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans;
int arr[10001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	ans = max(max(arr[n - 1] * arr[n - 2], arr[0] * arr[1] * arr[n - 1]), max(arr[n - 1] * arr[n - 2] * arr[n - 3], arr[0] * arr[1]));

	printf("%d\n", ans);
}