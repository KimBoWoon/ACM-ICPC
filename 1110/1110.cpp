#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int n;

int main() {
	int sum, cnt = 0, temp;

	scanf("%d", &n);

	temp = n;
	do {
		sum = (temp / 10) + (temp % 10);
		temp = ((temp % 10) * 10) + (sum % 10);
		cnt++;
	} while (temp != n);

	printf("%d\n", cnt);
}