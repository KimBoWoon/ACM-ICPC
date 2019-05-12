#include <bits/stdc++.h>
using namespace std;

int n, answer = -2e9;
int arr[100001], dp[100001];

int topDown(int x) {
	if (x == 0) {
		answer = arr[x];
		return arr[x];
	}

	dp[x] = max(arr[x], arr[x] + topDown(x - 1));
	answer = max(answer, dp[x]);
	
	return dp[x];
}

int bottomUp(int x) {
	for (int i = 0; i < x; i++) {
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	return answer;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	topDown(n);

	printf("%d\n", answer);
	// printf("%d\n", bottomUp(n));

	return 0;
}