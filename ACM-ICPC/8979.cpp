//
// Created by null on 11/27/17.
//

#define LOCAL

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Medal {
    int rank, gold, silver, bronze;
} medal;

int n, k;
vector<medal> v;

bool comp(const medal& x, const medal& y) {
    if (x.gold != y.gold) {
        return x.gold > y.gold;
    } else if (x.silver != y.silver) {
        return x.silver > y.silver;
    } else if (x.bronze != y.bronze) {
        return x.bronze > y.bronze;
    } else {
        return x.rank == k;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v.push_back({a, b, c, d});
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; i++) {
        if (v[i].rank == k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
}