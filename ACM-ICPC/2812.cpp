#include <iostream>
using namespace std;

int n, k, idx;
char c, stack[500000];

int main() {
	cin >> n >> k;

	while (n--) {
		cin >> c;

		while (k > 0 && idx > 0 && stack[idx - 1] < c) {
			idx--;
			k--;
		}
		stack[idx++] = c;
	}
	idx -= k;
	for (int i = 0; i < idx; i++) {
		cout << stack[i];
	}
	cout << endl;
}