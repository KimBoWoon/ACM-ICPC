#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	char s[50] = { 0 };
	int cnt[11] = { 0 };

	scanf("%d %d %d", &a, &b, &c);
	
	sprintf(s, "%d", a * b * c);

	for (int i = 0; s[i] != NULL; i++) {
		cnt[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << endl;
	}

	return 0;
}