#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int d[4001][4001];
char s1[4001], s2[4001];
int ans;

int main() {
	scanf("%s %s", &s1, &s2);

	for (int i = 0; s1[i]; i++) {
		for (int j = 0; s2[j]; j++) {
			if (s1[i] == s2[j]) {
				if (i == 0 || j == 0) {
					d[i][j] = 1;
				}
				else {
					d[i][j] = d[i - 1][j - 1] + 1;
				}
				if (d[i][j] > ans) {
					ans = d[i][j];
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}