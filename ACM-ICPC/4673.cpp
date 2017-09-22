#include <cstdio>
using namespace std;

bool n[10001];

int f(int i) {
	return i + ((i / 10000) % 10) + ((i / 1000) % 10) + ((i / 100) % 10) + ((i / 10) % 10) + (i % 10);
}

int main() {
	for (int i = 1; i < 10000; i++) {
		n[f(i)] = true;
	}

	for (int i = 1; i < 10000; i++) {
		if (!n[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}