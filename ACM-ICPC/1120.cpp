#include <cstdio>
#include <cstring>
using namespace std;

int ans, min = 999999999;
char a[51], b[51];

int main() {
	scanf("%s %s", a, b);

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

// 어짜피 모자른 부분은 같은 문자로 채울 것이기 때문에
// 두 문자열을 모두 비교하여 다른 부분의 수가 적은것을 찾으면 된다