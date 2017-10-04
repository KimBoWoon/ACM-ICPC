//
// Created by secret on 10/4/17.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int n, hp, mp, attack, armor, a, b, c, d, ans;

int main() {
    scanf("%d", &n);

    while (n--) {
        scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &attack, &armor, &a, &b, &c, &d);

        printf("%d\n", max(hp + a, 1) + 5 * max(mp + b, 1) + 2 * max(attack + c, 0) + 2 * (armor + d));
    }
}