#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int time[1001];
int n, sum, ans;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
	}

	sort(time, time + n);

	sum = ans = time[0];
	for (int i = 1; i < n; i++) {
		sum += time[i];
		ans += sum;
	}

	printf("%d\n", ans);
}