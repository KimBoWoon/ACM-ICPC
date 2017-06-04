#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n = 0;
	char str[1000001];
	char* s;

	cin.getline(str, 1000001);

	s = strtok(str, " ");
	while (s != NULL) {
		n++;
		s = strtok(NULL, " ");
	}

	printf("%d\n", n);

	return 0;
}