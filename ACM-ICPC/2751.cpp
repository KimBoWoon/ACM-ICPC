#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	vector<int> v;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}