#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void parenthesis(string par, int begin);

int cnt = 0;

int main() {
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		string par;

		cin >> par;

		parenthesis(par, 0);

		if (cnt != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		cnt = 0;
	}
}

void parenthesis(string par, int begin) {
	if (par[begin] == '(')
		cnt++;
	else if (par[begin] == ')') {
		cnt--;

		if (cnt < 0)
			return;
	}

	if (par.size() == begin)
		return;
	else
		parenthesis(par, begin + 1);
}