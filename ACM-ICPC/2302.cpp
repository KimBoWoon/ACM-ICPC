#include <cstdio>

#define MAX 41

int n, m, answer = 1, temp;
int dp[41] = { 1, 1 };

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 2; i <= MAX; i++) { // 모든 경우의 수는 피보나치 수열이 된다
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		answer *= dp[x - temp - 1]; // 각 좌석마다 나올 수 있는 경우의 수를 모두 곱한다
		temp = x;
	}

	printf("%d\n", answer * dp[n - temp]); // 마지막 좌석 처리
}