#include <cstdio>
#include <cmath>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int a, b, v;

	scanf("%d %d %d", &a, &b, &v);

	printf("%d\n", (v - b - 1) / (a - b) + 1);
}