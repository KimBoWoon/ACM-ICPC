#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int arr[1001];
int n, sum, ans;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	// 정렬해서 제일 적은 시간부터 처리하면 최소 시간을 구할 수 있다
	sort(arr, arr + n);

	sum = ans = arr[0];
	for (int i = 1; i < n; i++) {
		sum += arr[i];
		ans += sum;
	}

	printf("%d\n", ans);
}