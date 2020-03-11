#include <cstdio>
using namespace std;

int n, answer;
int a[1001], dp[1001];

void lis(int& idx, int value) {
	if (idx == 0 || (idx > 0 && dp[idx - 1] <= value)) {
		dp[idx++] = value;
		return;
	}

	int start = 0, end = idx - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (dp[mid] < value) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	dp[end + 1] = value;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// int idx = 0;
	// for (int i = 0; i < n; i++) {
	// 	int sum = 0;

	// 	lis(idx, a[i]);

	// 	for (int j = 0; j < idx; j++) {
	// 		sum += dp[j];
	// 	}

	// 	if (sum > answer) {
	// 		answer = sum;
	// 	}
	// }

	// printf("%d\n", answer);

	for (int i = 0; i < n; i++) {
		dp[i] = a[i];
		
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + a[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	printf("%d\n", answer);
}

// lis 응용 문제
// dp 배열에 lis를 이루고 있을 때 최대합을 저장
// 알고있는 lis를 사용하여 풀면 안된다
// 증가하는 부분 수열의 '최대값'이다
// 10
// 1 100 55 50 60 3 5 6 7 8
// 위의 예제에서는 1 + 55 + 60 = 116이 정답이다
// 하지만 lis를 이용해서 풀면 1 + 50 + 60 = 111이 나온다