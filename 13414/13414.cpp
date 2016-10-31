#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int k, l;
string v[500001];
stack<string> s;
set<string> table;

int main() {
	cin >> k >> l;

	for (int i = 0; i < l; i++) {
		cin >> v[i];
	}

	for (int i = l - 1; i > -1; i--) {
		if (table.find(v[i]) == table.end()) {
			s.push(v[i]);
			table.insert(v[i]);
		}
	}

	for (int i = 0; i < k; i++) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}