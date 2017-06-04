#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Point {
	int start, end;
} point;

point p[100001];

bool comp(const point &x, const point &y) {
	if (x.end == y.end) {
		return x.start < y.start;
	}
	else {
		return x.end < y.end;
	}
}

int main() {
	int n, ans = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		p[i].start = x;
		p[i].end = y;
	}

	sort(p, p + n, comp);

	int max = p[0].end;

	for (int i = 1; i < n; i++) {
		if (max <= p[i].start) {
			max = p[i].end;
			ans++;
		}
	}

	printf("%d\n", ans);
}