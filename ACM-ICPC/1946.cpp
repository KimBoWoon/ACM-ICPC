#include <cstdio>
using namespace std;

int t, n, rx, ry;
int rank[100001];

int recruit() {
	int min = rank[1], ans = 1; // 서류순으로는 이미 정렬되어 있기 때문에 면접 결과만 가지고 비교하면된다

	for (int i = 1; i <= n; i++) {
		if (min > rank[i]) { // i - 1 번째 사람까지 최상의 면접 결과 > i번째 사람의 면접결과
			ans++; // 채용
			min = rank[i]; // 최상의 면접결과 변경
		}
	}

	return ans;
}

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &rx, &ry);
			rank[rx] = ry;
		}

		printf("%d\n", recruit());
	}
}