#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable:4996)

string s;
string v = "aeiou";
int cnt;

int main() {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (s[i] == v[j]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}