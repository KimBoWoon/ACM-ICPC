#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

char s[101];

int palindrome(char s[101]) {
	for (int i = 0, j = strlen(s) - 1; i < j;) {
		if (s[i] != s[j]) {
			return 0;
		}
		else {
			i++;
			j--;
		}
	}

	return 1;
}

int main() {
	scanf("%s", &s);

	printf("%d\n", palindrome(s));
}