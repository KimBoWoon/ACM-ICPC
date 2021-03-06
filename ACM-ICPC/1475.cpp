#include <iostream>
#include <string>
using namespace std;

string s;
int num[10];

/*
9를 모두 6으로 변경한 뒤에 6 / 2를 하면된다
홀수일 경우를 위해 나머지 값도 더해준다
*/

int main() {
	int max = 0;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '9') {
			s[i] = '6';
		}
		num[s[i] - '0']++;
	}

	num[6] = num[6] / 2 + num[6] % 2;

	for (int i = 0; i < 9; i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}

	cout << max << endl;
}