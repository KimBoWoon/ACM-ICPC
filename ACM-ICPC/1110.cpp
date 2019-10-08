#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int n;

/*
문제에 나온 식을 그대로 사용
*/

int main() {
	int sum, cnt = 0, temp;

	scanf("%d", &n);

	temp = n;
	do {
		// 자릿수 합
		sum = (temp / 10) + (temp % 10);
		// 주어진 수의 가장 오른쪽 수와 더한 수의 가장 오른쪽수 연결
		temp = ((temp % 10) * 10) + (sum % 10);
		cnt++;
	} while (temp != n);

	printf("%d\n", cnt);
}