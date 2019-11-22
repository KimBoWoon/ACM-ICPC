#include <cstdio>
#include <algorithm>
using namespace std;

int n, weight;
int arr[100001];

/*
[10, 15] 의 로프가 있을 때
15 / 1 = 15 이므로 15의 무게를 견딜 수 있다
(10 + 15) / 2 = 12.5 이므로 무게 10을 결딜 수 있는 로프는 견디지 못한다
그래서 사용한 로프는 2개 최대 하중은 10 이므로
10 * 2 = 20의 무게를 견딜 수 있다
*/

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