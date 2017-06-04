#include<cstdio>
using namespace std;

#pragma warning(disable:4996)

int testcase, left, right;
int ans = 0;
unsigned long long dp[31][31];

void fill_dp(int l, int r) {
	for (int i = 0; i < l; i++) {
		dp[i][0] = 1;
	}
	for (int j = 0; j < r; j++) {
		dp[j][j] = 1;
	}
	for (int i = 1; i < l; i++) {
		for (int j = 1; j < r; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}
int main() {
	fill_dp(31, 31);
	
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		ans = 0;
		scanf("%d %d", &left, &right);
		printf("%lld\n", dp[right][left]);
	}
	return 0;
}