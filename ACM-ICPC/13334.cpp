#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

typedef struct point {
	int start, end;
} Point;

bool comp(const Point &p1, const Point &p2) {
	if (p1.start == p2.start)
		return p1.end < p2.end;
	return p1.start < p2.start;
}

Point v[100001];

int main() {
	int n = 0, d = 0, cnt = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &v[i].start, &v[i].end);
		if (v[i].start > v[i].end)
			swap(v[i].start, v[i].end);
	}

	sort(v, v + n, comp);

	scanf("%d", &d);

	for (int i = 0; i < n; ++i) {
		if (v[i].end - d) {

		}
	}

	printf("%d\n", cnt);
}