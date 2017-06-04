#include <cstdio>
#include <cmath>
using namespace std;

#pragma warning(disable:4996)

int arr[16];
int n, ans;

bool check(int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[n] || (n - i) == abs(arr[i] - arr[n])) {
			return false;
		}
	}
	return true;
}

void f(int n) {
	if (n == ::n) {
		ans++;
	}
	else {
		for (int i = 0; i < ::n; i++) {
			arr[n] = i;
			if (check(n))
				f(n + 1);
		}
	}
}

int main() {
	scanf("%d", &n);

	f(0);

	printf("%d\n", ans);
}