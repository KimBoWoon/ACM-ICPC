#define LOCAL

#include <iostream>
#include <string>
using namespace std;

int maxSize;
string s[5];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
		if (maxSize < s[i].size()) {
			maxSize = s[i].size();
		}
	}

	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[j].size() <= i) {
				continue;
			}
			cout << s[j][i];
		}
	}
	cout << endl;
}