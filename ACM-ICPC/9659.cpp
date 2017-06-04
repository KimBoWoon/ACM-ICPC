#include <iostream>
using namespace std;

typedef unsigned long long UNLLONG;

int main() {
	UNLLONG n = 0;

	cin >> n;

	if (n % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
}