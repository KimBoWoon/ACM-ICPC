#include <cstdio>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int n;
char arr[65][65];

void func(int x, int y, int n) {
	bool flag = false;
	char c = arr[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c != arr[i + x][j + y]) {
				flag = true;
			}
		}
	}

	if (flag) {
		printf("(");
		n /= 2;
		func(x, y, n);
		func(x, y + n, n);
		func(x + n, y, n);
		func(x + n, y + n, n);
		printf(")");
	}
	else {
		printf("%c", c);
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}

	func(0, 0, n);
	printf("\n");
}