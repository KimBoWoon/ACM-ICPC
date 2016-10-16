#include <cstdio>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

int main() {
	priority_queue<int> q;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		if (q.empty() && x == 0) {
			printf("0\n");
		}
		else if (x == 0) {
			printf("%d\n", q.top());
			q.pop();
		}
		else {
			q.push(x);
		}
	}
}