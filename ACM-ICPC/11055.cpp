#include <cstdio>
using namespace std;

int n, answer;
int a[1001], dp[1001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int temp = 0;
		
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				if (temp < dp[j]) {
					temp = dp[j];
				}
			}
		}
		dp[i] = temp + a[i];
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	printf("%d\n", answer);
}