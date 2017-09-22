#include <iostream>
using namespace std;

int main() {
	int n = 0, k = 0;
	int money[10001] = { 0 }, coin[101] = { 0 };

	cin >> n >> k;

	money[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];

		for (int j = coin[i]; j <= k; j++)
			money[j] = money[j] + money[j - coin[i]];
	}

	cout << money[k] << endl;
}