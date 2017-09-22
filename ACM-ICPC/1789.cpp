#include <cstdio>
using namespace std;

unsigned long long s, sum, max;

int main() {
	scanf("%lld", &s);

	for (int i = 1; ; i++) {
		sum += i;
		if (s < sum) {
			max = i;
			break;
		}
	}

	printf("%d\n", max - 1);
}