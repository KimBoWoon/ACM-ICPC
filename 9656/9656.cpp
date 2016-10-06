#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n = 0;

	//freopen("input.txt", "r", stdin);

	cin >> n;

	if (n % 2 != 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
}