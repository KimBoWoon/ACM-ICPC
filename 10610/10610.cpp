#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
int number[10];
int sum;

int main() {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
		number[s[i] - '0']++;
	}

	if (sum % 3 || !number[0]) {
		cout << -1;
	}
	else {
		for (int i = 9; i >= 0; i--) {
			while (number[i]--) {
				cout << i;
			}
		}
	}

	cout << endl;

	return 0;
}