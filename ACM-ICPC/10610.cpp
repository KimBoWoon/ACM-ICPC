#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
int number[10];
int sum;

int main() {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
		number[s[i] - '0']++;
	}

	// 30의 배수는 3으로 나누어 떨어지거나 0이 한번이라도 등장해야한다
	if (sum % 3 || !number[0]) {
		cout << -1;
	}
	else {
		// 제일 큰 수 부터 출력하면 제일 큰 수를 만들 수 있다
		for (int i = 9; i >= 0; i--) {
			while (number[i]--) {
				cout << i;
			}
		}
	}

	cout << endl;

	return 0;
}