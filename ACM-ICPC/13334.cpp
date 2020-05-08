// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int x[100000], y[100000], cnt, s, r, n, d;
// pair<int, int> p[200000];

// int main() {
// 	scanf("%d", &n);

// 	for (int i = 0; i < n; i++) {
// 		scanf("%d %d", x + i, y + i);
// 	}

// 	scanf("%d", &d);

// 	for (int i = 0; i < n; i++) {
// 		if (x[i] > y[i]) {
// 			swap(x[i], y[i]);
// 		}

// 		if (y[i] - x[i] > d) {
// 			continue;
// 		}

// 		p[cnt++] = { y[i] - d, -1 };
// 		p[cnt++] = { x[i], 1 };
// 	}

// 	sort(p, p + cnt);

// 	for (int i = 0; i < cnt; i++) {
// 		s -= p[i].second;
// 		if (r < s) {
// 			r = s;
// 		}
// 	}

// 	printf("%d\n", r);

// 	return 0;
// }

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Line {
	int start, end;
} line;

int n, d, answer;
line l[100001];
priority_queue<int> pq;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		if (x < y) {
			l[i].start = x;
			l[i].end = y;
		} else {
			l[i].start = y;
			l[i].end = x;
		}
	}

	scanf("%d", &d);

	sort(l, l + n, [](const line &x, const line &y) -> bool { return x.end < y.end; });

	for (int i = 0; i < n; i++) {
		pq.push(-l[i].start); // i번째 시작을 우선순위 큐에 저장

		while (!pq.empty() && -pq.top() < l[i].end - d) { // 큐가 비어있지 않고 철도 길이를 초과한다면
			pq.pop();
		}

		answer = max(answer, (int) pq.size());
	}

	printf("%d\n", answer);
}