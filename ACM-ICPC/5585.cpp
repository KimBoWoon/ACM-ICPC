#include <cstdio>
using namespace std;

int n, sum, ans;
int coin[] = { 500, 100, 50, 10, 5, 1 };

int main() {
	scanf("%d", &n);

	sum = 1000 - n;

	// 제일 큰 값부터 빼주면 된다
	for (int i = 0; sum != 0;) {
		if (sum >= coin[i]) {
			sum -= coin[i];
			ans++;
		}
		else {
			i++;
		}
	}
	
	printf("%d\n", ans);
}