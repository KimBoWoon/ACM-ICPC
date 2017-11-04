#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int a, b, c;
long long ans = 1;

int power(int n, int k) {
	// ���� ���: n^0 = 1
	if (k == 0) {
		return 1;
	}

	int temp = power(n, k / 2);
	int result = 1LL * temp * temp % c;
	// Ȧ���̸� n�� �� �� �� �����ش�.
	if (k % 2) {
		result = 1LL * result * n % c;
	}
	return result;
}

int main() {
	ifstream cin("input.txt");

	cin >> a >> b >> c;

	cout << power(a, b) << endl;
}