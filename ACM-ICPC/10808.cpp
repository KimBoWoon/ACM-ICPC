#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int main() {
	char str[101] = { 0 };
	int alphabet[26] = { 0 };

	scanf("%s", &str);

	for (int i = 0; str[i] != 0; i++) {
		alphabet[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	printf("\n");
}