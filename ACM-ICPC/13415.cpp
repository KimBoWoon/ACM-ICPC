#include <bits/stdc++.h>
using namespace std;

int n, k, x, y, temp;
int arr[100001];
stack<int> s;
deque<int> dq;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);

		temp = max(temp, max(x, y));

		while (!s.empty() && abs(s.top()) < x) {
			s.pop();
		}
		s.push(x);

		while (!s.empty() && abs(s.top()) < y) {
			s.pop();
		}
		s.push(-y);
	}

	sort(arr + 1, arr + temp + 1);

	for (int i = 1; i <= temp; i++) {
		dq.push_back(arr[i]);
	}

	stack<int> s1;
	while (!s.empty()) {
		s1.push(s.top());
		s.pop();
	}

	while (!s1.empty()) {
		int cur = s1.top();
		s1.pop();
		int prev = 0;
		if (!s1.empty()) {
			prev = abs(s1.top());
		}
		if (cur > 0) {
			for (int i = cur; i > prev; i--) {
				arr[i] = dq.back();
				dq.pop_back();
			}
		} else {
			for (int i = -cur; i > prev; i--) {
				arr[i] = dq.front();
				dq.pop_front();
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}