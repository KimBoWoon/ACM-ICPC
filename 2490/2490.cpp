#include <cstdio>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int x, ans = 0;

		for (int j = 0; j < 4; j++) {
			scanf("%d", &x);

			if (x == 0) {
				ans++;
			}
		}

		switch (ans) {
		case 1:
			printf("A\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("C\n");
			break;
		case 0:
			printf("E\n");
			break;
		case 4:
			printf("D\n");
			break;
		default:
			break;
		}
	}
}