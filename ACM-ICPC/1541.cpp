#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char s[101];
int num, sum;
bool sub;

int main() {
	scanf("%s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num = 10 * num + (s[i] - '0');
		} else {
			if (!sub) {
				sum += num;
			} else {
				sum -= num;
			}

			num = 0;
			sub |= s[i] == '-';
		}
	}

	if (!sub) {
		sum += num;
	} else {
		sum -= num;
	}

	printf("%d\n", sum);
}

// - 를 만나기 전까지 모든 값들을 더한다
// - 를 만나면 다음 - 를 만나기 전까지 모두 빼버린다
// 괄호가 있다고 생각하면 - 뒤에 있는 + 는 분배법칙으로 모두 - 가 되기 때문