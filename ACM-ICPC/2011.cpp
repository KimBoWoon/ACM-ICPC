#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 1000000

char n[5002];
int dp[5001];

int main() {
	scanf("%s", n + 1);
	int slen = strlen(n + 1);
	dp[0] = 1;

	for (int i = 1; i <= slen; i++) {
		int x = n[i] - '0';

		if (x >= 1 && x <= 9) { // 한 자리 수 일 때
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}

		if (n[i - 1] == '0') { // 두 자리 수가 될 수 없는 경우 넘어간다
			continue;
		}

		int y = (n[i - 1] - '0') * 10 + (n[i] - '0'); // 두 자리 수 일 경우

		if (y >= 10 && y <= 26) { // 두 자리 수 일 때
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}

	printf("%d\n", dp[slen]);

	return 0;
}