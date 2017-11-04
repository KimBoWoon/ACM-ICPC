#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

int n, ans;

int main() {
	cin >> n;

	ans = n;

	for (int i = 0; i < n; i++) {
		int check[26] = { 0 };
		string s;

		cin >> s;
		memset(check, -1, sizeof(int) * 26);

		for (int j = 0; j < s.size(); j++) {
			if (check[s[j] - 'a'] == -1 || check[s[j] - 'a'] == j - 1) {
				check[s[j] - 'a'] = j;
			}
			else {
				ans--;
				break;
			}
		}
	}

	cout << ans << endl;
}