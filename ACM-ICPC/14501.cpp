#include <cstdio>
#include <algorithm>
using namespace std;

int n, result;
int consulting[2][16];
int ans[16];

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &consulting[0][i], &consulting[1][i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + consulting[0][i]; j <= n + 1; j++) {
			ans[j] = max(ans[j], ans[i] + consulting[1][i]);
		}
	}

	printf("%d\n", ans[n + 1]);
}

// n + 1일에 퇴사를 한다
// 바꿔 말하면 n + 1일 동안은 일을 한다
// i 째날 + consulting[0][i] : i 째날 부터 시작해서 상담 기간
// n + 1일이 되는 날 퇴사이니 이때까지 반복문 실행
// 반복문을 돌리며 최대값을 찾는다