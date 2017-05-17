#include <cstdio>
#include <string>
using namespace std;

int n, ans;
int a[3];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			ans = i;
		}
		else if (i == 1000) {
			break;
		}
		else {
			int k = 0, t = i;
			while (t > 0) {
				a[k] = t % 10;
				t /= 10; k++;
			}
			if (a[0] - a[1] == a[1] - a[2]) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}