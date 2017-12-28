//
// Created by null on 12/3/17.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int a[26];
string ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        a[s[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] >= 5) {
            ans += i + 'a';
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() > 0) {
        cout << ans << endl;
    } else {
        cout << "PREDAJA" << endl;
    }
}