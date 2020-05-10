#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Point {
	int start, end;
} point;

int n, ans = 1;
point p[100001];

// 회의 종료 시간 오름차순 정렬
// 종료 시간이 같으면 시작 시간 오름차순 정렬
bool comp(const point &x, const point &y) {
	if (x.end == y.end) {
		return x.start < y.start;
	}
	else {
		return x.end < y.end;
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].start, &p[i].end);
	}

	sort(p, p + n, comp);

	int max = p[0].end;

	for (int i = 1; i < n; i++) {
		if (max <= p[i].start) { // 다음 회의 시작 시간이 이전 회의 종료 시간보다 크면
			max = p[i].end; // 다음 회의 종료 시간 저장
			ans++; // 회의를 진행할 수 있다
		}
	}

	printf("%d\n", ans);
}