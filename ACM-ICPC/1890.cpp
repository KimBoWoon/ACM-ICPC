#define LOCAL

#include <cstdio>
using namespace std;

int n, x, y;
int map[101][101];
long long ans;
long long dp[101][101];

bool check(int x, int y) {
	if (x < n && y < n) {
		return true;
	}
	return false;
}

//long long jump(int x, int y) {
//	if (x == n - 1 && y == n - 1) {
//		return ++ans;
//	}
//	if (check(x + map[x][y], y)) {
//		jump(x + map[x][y], y);
//	}
//	if (check(x, y + map[x][y])) {
//		jump(x, y + map[x][y]);
//	}
//}

void jump() {
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) {
				continue;
			}

			x = map[i][j] + i;
			y = map[i][j] + j;

			if (x < n) {
				dp[x][j] += dp[i][j];
			}
			if (y < n) {
				dp[i][y] += dp[i][j];
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//jump(0, 0);
	jump();

	//printf("%lld\n", ans);
	printf("%lld\n", dp[n - 1][n - 1]);
}