//
// Created by secret on 5/7/17.
//

#include <algorithm>
#include <iostream>
using namespace std;

int n[3];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> n[i];
    }

    sort(n, n + 3);

    for (int i = 0; i < 3; i++) {
        char a;
        cin >> a;
        cout << n[a - 'A'] << " ";
    }
    cout << endl;

    return 0;
}