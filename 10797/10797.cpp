#include <cstdio>
using namespace std;

int n, ans;
int arr[6];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (arr[i] == n) {
			ans++;
		}
	}

	printf("%d\n", ans);
}