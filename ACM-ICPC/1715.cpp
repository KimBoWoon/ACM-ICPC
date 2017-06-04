#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

#pragma warning(disable:4996)

typedef unsigned long long ULLONG;

int main() {
	priority_queue<int, vector<int>, greater<int> > q;
	int n, x;
	ULLONG sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		q.push(x);
	}

	int a, b;
	while (q.size() != 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a + b);
		sum += a + b;
	}

	printf("%lld\n", sum);

	return 0;
}