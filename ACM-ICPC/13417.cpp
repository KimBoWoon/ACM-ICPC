#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int tc;

	cin >> tc;

	while (tc--) {
		int n;
		string result;
		char input;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> input;

			if (i == 0) {
				result += input;
			}
			else {
				if (result[0] < input) {
					result += input;
				}
				else {
					result = input + result;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}