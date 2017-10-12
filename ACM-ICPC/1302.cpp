#define LOCAL

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, maxNum;
string ans;
map<string, int> m;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;

		map<string, int>::iterator iter = m.find(s);

		if (m.end() == iter) {
			m.insert(pair<string, int>(s, 1));
		}
		else {
			(*iter).second++;
		}
	}
	
	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if ((*iter).second > maxNum) {
			ans = (*iter).first;
			maxNum = (*iter).second;
		}
	}
	cout << ans << endl;
}