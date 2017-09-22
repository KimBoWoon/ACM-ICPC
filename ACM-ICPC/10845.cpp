#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	queue<int> q;
	int n;

	scanf("%d", &n);

	while (n--) {
		string str;
		int x;

		cin >> str;

		if (!str.compare("push")) {
			scanf("%d", &x);
			q.push(x);
		}
		else if (!str.compare("pop")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (!str.compare("size")) {
			printf("%ld\n", q.size());
		}
		else if (!str.compare("empty")) {
			if (q.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!str.compare("front")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front());
			}
		}
		else if (!str.compare("back")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.back());
			}
		}
	}
}