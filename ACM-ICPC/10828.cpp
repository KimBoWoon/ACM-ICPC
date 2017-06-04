#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int t;
	stack<int> s;

	scanf("%d", &t);

	while (t--) {
		int x;
		string str;

		cin >> str;
		
		if (!str.compare("push")) {
			scanf("%d", &x);
			s.push(x);
		}
		else if (!str.compare("top")) {
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
		}
		else if (!str.compare("size"))
			printf("%d\n", s.size());
		else if (!str.compare("pop")) {
			if (s.empty())
				printf("-1\n");
			else {
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (!str.compare("empty")) {
			if (s.empty())
				printf("1\n");
			else
				printf("0\n");
		}
	}
}