#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int main() {
	char str[101] = { 0 };
	char result[101] = { 0 };
	char *c = NULL;
	int i = 0;

	scanf("%s", &str);

	c = strtok(str, "-");
	while (c != NULL) {
		result[i++] = *c;
		c = strtok(NULL, "-");
	}

	printf("%s\n", result);
}