#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string num[1000];

// 문자열로 읽어 들인 숫자를 a + b 또는 b + a 로 조합할 수 있다
// 이 때 a + b 가 크다면 a 를 b + a가 크다면 b를 앞에 둬야한다
bool comp(const string& x, const string& y) {
    return x + y > y + x;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n, comp);

    if (num[0] == "0") {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << num[i];
        }
        cout << endl;
    }
}