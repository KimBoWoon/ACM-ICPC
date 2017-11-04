//
// Created by secret on 10/7/17.
//

#include <cstdio>

using namespace std;

typedef long long LLONG;

int n;
LLONG map[61][61];

LLONG split(int x, int y) {
    if (x > 0) {
        if (map[x][y] != 0) {
            return map[x][y];
        }
    }
    if (x == 0) {
        map[x][y] = 1;
        return 1;
    } else {
        LLONG sum = 0;
        sum += split(x - 1, y + 1);
        if (y >= 1) {
            sum += split(x, y - 1);
        }
        map[x][y] = sum;
        return sum;
    }
}

int main() {
    scanf("%d", &n);

    while (n != 0) {
        printf("%lld\n", split(n - 1, 1));

        scanf("%d", &n);
    }
}