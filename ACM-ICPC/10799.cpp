//
// Created by secret on 5/20/17.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string in;
int ans;

int main() {
    cin >> in;

    for (int i = 0; i < in.size(); i++) {
        if (in[i] == '(') {
            s.push('(');
        } else {
            s.pop();

            if (in[i - 1] == '(') {
                ans += s.size();
            } else {
                ans++;
            }
        }
    }

    cout << ans << endl;
}