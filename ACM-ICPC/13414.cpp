#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

int k, l, data;
map<int, int> m;
vector<pair<int, int> > v;

bool comp(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second < y.second;
}

int main() {
	scanf("%d %d", &k, &l);

	for (int i = 0; i < l; i++) {
		scanf("%d", &data);
		m[data] = i + 1;
	}

	v = vector<pair<int, int> >(m.begin(), m.end());

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < k && i < v.size(); i++) {
		printf("%08d\n", v[i].first);
	}

	return 0;
}