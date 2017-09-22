#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	while (n--) {
		char s[100];
		int sum = 0, cnt = 1;

		scanf("%s", &s);

		for (int i = 0; i < s[i] != 0; i++) {
			if (s[i] == 'O') {
				sum += cnt++;
			}
			else if (s[i] == 'X') {
				cnt = 1;
			}
		}

		printf("%d\n", sum);
	}
}