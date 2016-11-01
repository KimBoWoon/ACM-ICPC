#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

int k, l;
string s;
map<string, int> m;
vector<pair<int, string> > v;

int main() {
    cin >> k >> l;

    for (int i = 0; i < l; i++) {
        cin >> s;
        m[s] = i + 1;
    }

    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        v.push_back({iter->second, iter->first});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++) {
        cout << v[i].second << endl;
    }

    return 0;
}