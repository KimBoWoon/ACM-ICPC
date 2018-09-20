#include <iostream>
#include <string>
using namespace std;

string s;
string croatia[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int ans;

int main() {
	cin >> s;

	for (int i = 0; i < s.size(); ) {
		if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) {
			ans++;
			i += 2;
		}
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
			ans++;
			i += 3;
		}
		else if (s[i] == 'd' && s[i + 1] == '-') {
			ans++;
			i += 2;
		}
		else if ((s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j') {
			ans++;
			i += 2;
		}
		else if ((s[i] == 's' || s[i] == 'z') && s[i + 1] == '=') {
			ans++;
			i += 2;
		}
		else {
			ans++;
			i++;
		}
	}

	cout << ans << endl;
}