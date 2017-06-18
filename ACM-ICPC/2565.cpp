#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int n;
point p[101];
vector<int> v;

bool comp(const point& x, const point& y) {
	return x.x < y.x;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	sort(p, p + n, comp);

	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back(p[i].y);
		}
		else if (v[v.size() - 1] > p[i].y) {
			vector<int>::iterator idx = lower_bound(v.begin(), v.end(), p[i].y);
			*idx = p[i].y;
		}
		else if (v[v.size() - 1] < p[i].y) {
			v.push_back(p[i].y);
		}
	}

	printf("%d\n", n - v.size());
}