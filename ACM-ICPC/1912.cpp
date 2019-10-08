#include <bits/stdc++.h>
using namespace std;

int n, answer = -2e9;
int arr[100001], dp[100001];

/*
n번째 자리까지 합치면 이득인 경우 : arr[i] + dp[i - 1]
n번째 자리까지 합쳤는데 이득이 아닌 경우(새로 시작) : arr[i]
참고 : https://limkydev.tistory.com/120
*/

int topDown(int x) {
	if (x == 1) {
		answer = arr[x];
		return arr[x];
	}

	dp[x] = max(arr[x], arr[x] + topDown(x - 1));
	answer = max(answer, dp[x]);
	
	return dp[x];
}

int bottomUp(int x) {
	for (int i = 1; i <= x; i++) {
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	return answer;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	// topDown(n);

	// printf("%d\n", answer);
	printf("%d\n", bottomUp(n));

	return 0;
}