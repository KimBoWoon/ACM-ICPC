#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	string pattern;
	string input;

	scanf("%d", &n);

	cin >> pattern;

	for (int i = 1; i < n; i++) {
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (pattern[j] != input[j]) {
				pattern[j] = '?';
			}
			else {
				pattern[j] = input[j];
			}
		}
	}

	cout << pattern << endl;
}