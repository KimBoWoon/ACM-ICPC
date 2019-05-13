#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

int n, x;
vector<int> v;

int main() {
    scanf("%d", &n);

    v.push_back(INF);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (v.back() < x) {
            v.push_back(x);
        } else {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }

    printf("%d\n", v.size());
}