#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

char s1[1001], s2[1001], result[1001];
int lcsTable[1001][1001];
int s1Len, s2Len;

// 같은 문자일 경우 = 왼쪽 위에 값 + 1
// 다른 문자일 경우 = max(윗 값, 왼쪽 값)
int lcs() {
	for (int i = 1; i <= s1Len; i++) {
		for (int j = 1; j <= s2Len; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
			} else {
				if (lcsTable[i][j - 1] >= lcsTable[i - 1][j]) {
					lcsTable[i][j] = lcsTable[i][j - 1];
				} else {
					lcsTable[i][j] = lcsTable[i - 1][j];
				}
			}
		}
	}

	return lcsTable[s1Len][s2Len];
}

void lcsTraceBack(int x, int y) {
	if (x == 0 || y == 0) {
		return;
	}

	// 현재 값 > 왼쪽 값 && 현재 값 > 윗 값 && 현재 값 > 왼쪽 윗 값
	if (lcsTable[x][y] > lcsTable[x][y - 1] && lcsTable[x][y] > lcsTable[x - 1][y] && lcsTable[x][y] > lcsTable[x - 1][y - 1]) {
		lcsTraceBack(x - 1, y - 1); // 왼쪽 위로 변경
		printf("%c", s1[x - 1]); // 값 출력
	} else if (lcsTable[x][y] > lcsTable[x - 1][y] && lcsTable[x][y] == lcsTable[x][y - 1]) { // 현재 값 > 윗 값 && 현재 값 == 왼쪽 값
		lcsTraceBack(x, y - 1); // 왼쪽으로 변경
	} else {
		lcsTraceBack(x - 1, y); // 위로 변경
	}
}

int main() {
	scanf("%s %s", s1, s2);

	s1Len = strlen(s1);
	s2Len = strlen(s2);

	for (int i = 0; i <= s1Len; i++) {
		lcsTable[i][0] = 0;
	}

	for (int i = 0; i <= s2Len; i++) {
		lcsTable[0][i] = 0;
	}

	printf("%d\n", lcs());

	lcsTraceBack(s1Len, s2Len);
	printf("\n");

	return 0;
}