#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

string s;
vector<string> v;

int main() {
	cin >> s;

	int size = s.size();
	for (int i = 0; i < size; i++) {
		v.push_back(s);
		s.erase(s.begin());
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}