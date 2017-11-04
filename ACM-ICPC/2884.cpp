#define LOCAL

#include <cstdio>

int n, m;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &m);

	// (m + 15) / 60 은 60분일 때 한 시간 올리는 식
	// 24 시간제 이기 때문에 23을 더해준다
	printf("%d %d\n", (n + 23 + (m + 15) / 60) % 24, (m + 15) % 60);
}