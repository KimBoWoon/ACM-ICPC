#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int n, sum = 0, cnt = 0;
		int score[1001];
		double average = 0;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}

		average = sum / n;

		for (int i = 0; i < n; i++) {
			if (score[i] > average) {
				cnt++;
			}
		}

		printf("%.3lf%%\n", (double) ((double) cnt / (double) n) * 100.0);
	}
}