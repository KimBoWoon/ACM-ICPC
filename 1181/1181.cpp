#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string str[20001];
string temp;

bool comp(const string &x, const string &y) {
	if (x.size() == y.size()) {
		return x < y;
	}
	return x.size() < y.size();
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str + n, comp);

	for (int i = 0; i < n; i++) {
		if (str[i] == str[i + 1]) {
			continue;
		}
		cout << str[i] << endl;
	}
}