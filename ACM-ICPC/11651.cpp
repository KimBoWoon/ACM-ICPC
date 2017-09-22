#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x, y;
} point;

int n;
point p[100001];

bool comp(const point &x, const point &y) {
	if (x.y == y.y) {
		return x.x < y.x;
	}

	return x.y < y.y;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	sort(p, p + n, comp);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
}