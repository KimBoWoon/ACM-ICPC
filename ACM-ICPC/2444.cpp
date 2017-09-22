#include <iostream>
using namespace std;

int main() {
	int n;
	int line, space, star;

	cin >> n;

	for (line = 0; line < n; line++) {
		for (space = 0; space < (n - line - 1); space++)
			cout << ' ';
		for (star = 0; star < (2 * line + 1); star++)
			cout << '*';
		cout << endl;
	}
	for (line = n - 2; line >= 0; line--) {
		for (space = 0; space < (n - line - 1); space++)
			cout << ' ';
		for (star = 0; star < (2 * line + 1); star++)
			cout << '*';
		cout << endl;
	}

	return 0;
}