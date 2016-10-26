//
// Created by secret on 10/26/16.
//

#include <bits/stdc++.h>
#include <string>

using namespace std;

string v1, v2;

int main() {
    cin >> v1 >> v2;

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    int a = stoi(v1), b = stoi(v2);
    if (a > b) {
        cout << v1 << endl;
    } else {
        cout << v2 << endl;
    }
}