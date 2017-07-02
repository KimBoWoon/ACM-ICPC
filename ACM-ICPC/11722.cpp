//
// Created by secret on 7/2/17.
//

#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;

        scanf("%d", &x);

        x *= -1;

        if (v.empty()) {
            v.push_back(x);
        }
        else if (v[v.size() - 1] < x) {
            v.push_back(x);
        }
        else if (v[v.size() - 1] > x) {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }

    printf("%ld\n", v.size());
}