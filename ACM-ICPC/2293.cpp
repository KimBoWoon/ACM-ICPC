#include <cstdio>
using namespace std;

int n, k, x;
int money[10001];

int main() {
	scanf("%d %d", &n, &k);

	// 0원을 만드는 경우
	// 공집합도 하나의 그룹?
	money[0] = 1;
	// n개의 동전
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);

		// k원을 만드는 경우의 수 구하기
		// x원 부터 시작하는 이유 : x원 보다 작은 값은 당연히 x원으로 만들 수 없기 때문
		for (int j = x; j <= k; j++) {
			// j원을 만드는 경우의 수
			// 이전에 구해둔 경우의 수를 가지고 구하기
			money[j] = money[j] + money[j - x];
		}
	}

	printf("%d\n", money[k]);
}