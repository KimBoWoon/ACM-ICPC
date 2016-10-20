#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int n;
char arr[65][65];

char func(int n) {
	
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}

	cout << "(" << func(n) << ")" << endl;
}