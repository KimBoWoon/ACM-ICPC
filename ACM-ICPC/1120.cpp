#include <cstdio>
#include <cstring>
using namespace std;

int ans, min = 999999999;
char a[51], b[51];

int main() {
	scanf("%s %s", &a, &b);

	int lenA = strlen(a);
	int lenB = strlen(b);

	for (int i = 0; i <= lenB - lenA; i++) {
		ans = 0;

		for (int j = 0; j < lenA; j++) {
			if (a[j] != b[i + j]) {
				ans++;
			}
		}

		if (min > ans) {
			min = ans;
		}
	}

	printf("%d\n", min);
}