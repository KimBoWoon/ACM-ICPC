// #include <cstdio>

// int n, m;

// int main() {
// 	scanf("%d %d", &n, &m);
// 	if (n == 1) {
// 		printf("1\n");
// 	}
// 	else if (n == 2) {
// 		if (m <= 6) {
// 			printf("%d\n", (m + 1) / 2);
// 		}
// 		else {
// 			printf("4\n");
// 		}
// 	}
// 	else {
// 		if (m <= 4) {
// 			printf("%d\n", m);
// 		}
// 		else if (m == 5 || m == 6) {
// 			printf("4\n");
// 		}
// 		else {
// 			printf("%d\n", m - 2);
// 		}
// 	}
// 	return 0;
// }

#include <cstdio>
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);

	if (n == 1) {
		printf("1\n");
		return 0;
	}
	if (n == 2) {
		printf("%d\n", (4 < ((m + 1) / 2)) ? 4 : ((m + 1) / 2));
		return 0;
	}
	if (m < 7) {
		printf("%d\n", (4 < m) ? 4 : m);
		return 0;
	}
	printf("%d\n", m - 7 + 5);
	return 0;
}