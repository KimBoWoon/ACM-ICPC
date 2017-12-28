//
// Created by null on 11/29/17.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string a, b, c, ans;

int main() {
    cin >> a >> c >> b;

    int aLen = a.size(), bLen = b.size();
    ans += "1";

    if (c == "*") {
        for (int i = 0; i < (aLen + bLen) - 2; i++) {
            ans += "0";
        }
    } else if (c == "+") {
        string maxString;

        if (aLen == bLen) {
            ans = a;
            ans[0] = '2';
        } else {
            if (aLen > bLen) {
                maxString = a;
            } else {
                maxString = b;
            }

            for (int i = 0; i < maxString.size(); i++) {
                if (i == abs(aLen - bLen)) {
                    maxString[i] = '1';
                    ans = maxString;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}