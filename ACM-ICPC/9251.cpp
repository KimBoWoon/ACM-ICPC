#include <cstdio>
#include <cstring>
using namespace std;

inline int MAX(int a, int b) {
	return (a < b) ? b : a;
}

char s1[1001], s2[1001];
int lcsTable[1001][1001];
int s1Len, s2Len;

int lcs() {
	for (int i = 1; i <= s1Len; i++) {
		for (int j = 1; j <= s2Len; j++) {
			// 문자가 일치하면 좌측 상단 값 + 1
			if (s1[i - 1] == s2[j - 1]) {
				lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
			}
			else {
				// 문자가 일치하지 않으면 상단값과 좌측값 중 최댓값
				lcsTable[i][j] = MAX(lcsTable[i][j - 1], lcsTable[i - 1][j]);
			}
		}
	}

	return lcsTable[s1Len][s2Len];
}

int main() {
	scanf("%s %s", s1, s2);

	s1Len = strlen(s1);
	s2Len = strlen(s2);

	// 초기값 설정
	for (int i = 0; i <= s1Len; i++) {
		lcsTable[i][0] = 0;
	}

	// 초기값 설정
	for (int i = 0; i <= s2Len; i++) {
		lcsTable[0][i] = 0;
	}

	printf("%d\n", lcs());

	return 0;
}