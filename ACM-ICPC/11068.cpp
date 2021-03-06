#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool palindrome(int n) {
	for (int i = 2; i <= 64; i++) {
		int temp = n;
		string result = "";

		while (temp >= i) {
			result += (temp % i) + 48;
			temp /= i;
		}
		if (temp != 0)
			result += temp + 48;

		for (int start = 0, end = result.size() - 1;; start++, end--) {
			if (result[start] != result[end])
				break;
			else if (start > end)
				return true;
		}
	}
	return false;
}

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int n;

		cin >> n;

		if (palindrome(n))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}