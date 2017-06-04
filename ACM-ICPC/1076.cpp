//
// Created by secret on 4/3/17.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct Table {
    int value;
    int multiple;
} table;

table t[11];

int main() {
    string a, b, c;
    unsigned long long result;
    map<string, table> m;

    m.insert({"black", {0, 1}});
    m.insert({"brown", {1, 10}});
    m.insert({"red", {2, 100}});
    m.insert({"orange", {3, 1000}});
    m.insert({"yellow", {4, 10000}});
    m.insert({"green", {5, 100000}});
    m.insert({"blue", {6, 1000000}});
    m.insert({"violet", {7, 10000000}});
    m.insert({"grey", {8, 100000000}});
    m.insert({"white", {9, 1000000000}});

    cin >> a >> b >> c;

    result = (m.find(a)->second.value * 10) + m.find(b)->second.value;
    cout << result * m.find(c)->second.multiple << endl;

    return 0;
}