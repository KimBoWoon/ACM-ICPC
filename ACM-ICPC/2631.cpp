//
// Created by null on 10/31/17.
//

#define LOCAL

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        if (v.empty()) {
            v.push_back(x);
        }
        else if (v[v.size() - 1] < x) {
            v.push_back(x);
        }
        else if (v[v.size() - 1] > x) {
            vector<int>::iterator idx = lower_bound(v.begin(), v.end(), x);
            *idx = x;
        }
    }

    printf("%d\n", n - v.size());
}