#include <cstdio>
using namespace std;

char str[16], dial[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 0};
int ans;

int main() {
	scanf("%s", &str);

	for (int i = 0; str[i] != 0; i++) {
		ans += dial[str[i] - 'A' + 1] + 1;
	}

	printf("%d\n", ans);
}