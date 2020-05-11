#include <cstdio>
using namespace std;

int n, m, ans;
int before[51][51], after[51][51];

void change(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			before[i][j] = !before[i][j];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &before[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &after[i][j]);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (before[i][j] != after[i][j]) { // 값이 다르면 3x3영역 반전
				change(i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before[i][j] != after[i][j]) { // 그래도 다르면 만들 수 없는 배열이므로 -1 출력
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d\n", ans);
}