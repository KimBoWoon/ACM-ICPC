#include <iostream>
using namespace std;

int main() {
	int n = 0;
	bool* arr = NULL;

	cin >> n;

	arr = new bool[1001];

	arr[1] = false;
	arr[2] = true;
	arr[3] = false;
	arr[4] = false;

	for (int i = 5; i <= n; i++)
		arr[i] = !(arr[i - 1] || arr[i - 3] || arr[i - 4]);

	if (arr[n])
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
}