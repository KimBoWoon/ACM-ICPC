#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, diff1 = 0, diff2 = 0;
		string a, b;

		cin >> n >> a >> b;

		for (int i = 0; i < n; i++) {
			if (a[i] != b[i] && a[i] == 'W') {
				diff1++;
			}
			else if (a[i] != b[i] && a[i] == 'B') {
				diff2++;
			}
		}
		cout << max(diff1, diff2) << endl;
	}

	return 0;
}