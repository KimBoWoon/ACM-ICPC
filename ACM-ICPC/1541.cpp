#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char s[101];
int num, sum;
bool sub;

int main() {
	scanf("%s", &s);

	for (int i = 0; s[i] != '\0'; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num = 10 * num + (s[i] - '0');
		}
		else {
			if (!sub) {
				sum += num;
			}
			else {
				sum -= num;
			}

			num = 0;
			sub |= s[i] == '-';
		}
	}

	if (!sub) {
		sum += num;
	}
	else {
		sum -= num;
	}

	printf("%d\n", sum);
}