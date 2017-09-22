#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int t;

int main() {
	scanf("%d", &t);

	while (t--) {
		string s;

		cin >> s;

		int size = s.size();

		if (size % 2 == 0) {
			for (int i = 0; i < size; i += 2) {
				cout << s[i];
			}
			cout << endl;
			for (int i = 1; i < size; i += 2) {
				cout << s[i];
			}
			cout << endl;
		}
		else {
			s += s;
			size = s.size();

			for (int i = 0; i < size; i += 2) {
				cout << s[i];
			}
			cout << endl;
			for (int i = 1; i < size; i += 2) {
				cout << s[i];
			}
			cout << endl;
		}
	}

	return 0;
}