#include<cstdio>
#include<algorithm>
using namespace std;

int x[100000], y[100000], cnt, s, r, n, d;
pair<int, int> p[200000];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", x + i, y + i);
	}

	scanf("%d", &d);

	for (int i = 0; i < n; i++) {
		if (x[i] > y[i]) {
			swap(x[i], y[i]);
		}

		if (y[i] - x[i] > d) {
			continue;
		}

		p[cnt++] = { y[i] - d,-1 };
		p[cnt++] = { x[i],1 };
	}

	sort(p, p + cnt);

	for (int i = 0; i < cnt; i++) {
		s -= p[i].second;
		if (r < s) {
			r = s;
		}
	}

	printf("%d\n", r);

	return 0;
}