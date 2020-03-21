#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

long long cost;
int dp[101];

void setup() {
    int m[] = { 1, 10, 25 };

	dp[0] = 0;

	for (int i = 1; i <= 99; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < 3; j++) {
			if (i - m[j] >= 0) {
				dp[i] = min(dp[i], dp[i - m[j]] + 1);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

    setup();

	while (t--) {
        long long answer = 0;

		scanf("%lld", &cost);

		while (cost) {
			int s = cost % 100;
			answer += dp[s];
			cost /= 100;
		}

		printf("%lld\n", answer);
	}
}

/*
동전은
1, 10, 25
100, 1000, 2500
10000, 100000, 250000
이런식이다

바꿔 말하면 1, 10, 25를 사용하여 모든 경우를 보면된다
*/


// #include <cstdio>
// #include <cmath>
// using namespace std;

// int t;
// long long answer;

// int getLen(long long num) {
//     int len = 0;

//     while (num > 0) {
//         num /= 10;
//         len++;
//     }
 
//     return len;
// }

// void f(long long cost, long long sum) {
//     if (sum > answer) {
//         return;
//     }

//     if (cost < 0) {
//         return;
//     }

//     if (cost == 0) {
//         answer = (sum < answer) ? sum : answer;
//         return;
//     }

//     int len = getLen(cost);
//     long long a = pow(10, len - 1);
//     long long b = pow(10, len - 2);

//     f(cost - (cost / a) * a, sum + (cost / a));

//     if (len % 2 == 0) {
//         f(cost - 25 * b, sum + 1);
//     }
// }

// int main() {
//     scanf("%d", &t);

//     while (t--) {
//         long long x;
//         answer = 987654321;

//         scanf("%lld", &x);

//         f(x, 0);

//         printf("%lld\n", answer);
//     }
// }