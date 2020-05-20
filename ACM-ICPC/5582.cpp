#include <cstdio>
#include <cstring>
using namespace std;

int dp[4001][4001];
char s1[4001], s2[4001];
int answer;

int main() {
	scanf("%s %s", s1, s2);

	for (int i = 0; s1[i]; i++) { // s1의 글자 인덱스
		for (int j = 0; s2[j]; j++) { // s2의 글자 인덱스
			if (s1[i] == s2[j]) { // s1과 s2의 문자가 서로 같으면
				if (i == 0 || j == 0) { // 시작 문자일 경우 이전 결과가 없으므로 1을 저장
					dp[i][j] = 1;
				} else { // 아니면 이전 값을 참고해 +1 한 값을 저장
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}

				if (dp[i][j] > answer) { // 최대값을 저장
					answer = dp[i][j];
				}
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}