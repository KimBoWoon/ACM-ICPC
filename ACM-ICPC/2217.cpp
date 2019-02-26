#include <cstdio>
#include <algorithm>
using namespace std;

int n, weight;
int arr[100001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	// 로프마다 들수 있는 중량이 다르다
	// 그래서 제일 작은 중량 값 * 로프의 개수를 해주면 답이 나온다
	for (int i = n - 1; i >= 0; i--) {
		weight = max(weight, arr[i] * (n - i));
	}

	printf("%d\n", weight);
}