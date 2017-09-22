#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string x, y, sum;

	cin >> x >> y;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	sum = to_string(stoi(x) + stoi(y));

	reverse(sum.begin(), sum.end());

	cout << stoi(sum) << endl;
}