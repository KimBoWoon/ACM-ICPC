#include <cstdio>
using namespace std;

int main() {
	int n, sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < 9; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
	}

	printf("%d\n", n - sum);
}