#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

char s1[1001], s2[1001], result[1001];
int lcsTable[1001][1001];
int s1Len, s2Len;

int lcs() {
	for (int i = 1; i <= s1Len; i++) {
		for (int j = 1; j <= s2Len; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
			}
			else {
				if (lcsTable[i][j - 1] >= lcsTable[i - 1][j]) {
					lcsTable[i][j] = lcsTable[i][j - 1];
				}
				else {
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

	if (lcsTable[x][y] > lcsTable[x][y - 1] &&
		lcsTable[x][y] > lcsTable[x - 1][y] &&
		lcsTable[x][y] > lcsTable[x - 1][y - 1]) {
		lcsTraceBack(x - 1, y - 1);
		printf("%c", s1[x - 1]);
	}
	else if (lcsTable[x][y] > lcsTable[x - 1][y] &&
		lcsTable[x][y] == lcsTable[x][y - 1]) {
		lcsTraceBack(x, y - 1);
	}
	else {
		lcsTraceBack(x - 1, y);
	}
}

int main() {
	scanf("%s %s", &s1, &s2);

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