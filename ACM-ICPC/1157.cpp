#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool flag = false;
int n;
int alphabet[26];
string s;

int main() {
	int max = 0;

	cin >> s;
	::transform(s.begin(), s.end(), s.begin(), ::toupper);

	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (max == alphabet[i]) {
			flag = true;
		}
		else if (alphabet[i] > max) {
			max = alphabet[i];
			flag = false;
			n = i;
		}
	}

	if (!flag) {
		printf("%c\n", 'A' + n);
	}
	else {
		printf("?\n");
	}
}