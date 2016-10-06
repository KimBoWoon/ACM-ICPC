#include <cstdio>
#include <stack>

using namespace std;

#pragma warning(disable:4996)

int main() {
	int n = 0, height = 0;
	int *arr = NULL;
	stack<int> s;

	scanf("%d", &n);

	while (true) {
		int temp;

		scanf("%d", &temp);
		s.push(temp);

		if (height > s.top()) {
			printf("%d ", 1);
		}
		else {
			printf("0 ");
		}
	}

	return 0;
}