#include <cstdio>
using namespace std;

int main() {
	int score[5] = { 0 };
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (score[i] < 40) {
			sum += 40;
		}
		else {
			sum += score[i];
		}
	}

	printf("%d\n", sum / 5);
}