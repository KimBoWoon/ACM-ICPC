#include <iostream>
#include <string>
using namespace std;

string str, explosion, ans;

bool isMatching(int s) {
	for (int i = s; i < s + explosion.size(); i++) {
		if (ans[i] != explosion[i - s]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> str >> explosion;

	for (int i = 0; i < str.size(); i++) {
		ans += str[i];
		if (((int)ans.size() - (int)explosion.size()) >= 0 && isMatching(ans.size() - explosion.size())) {
			ans.erase(ans.size() - explosion.size(), explosion.size());
		}
	}

	cout << ((ans.size() != 0) ? ans : "FRULA") << endl;
}