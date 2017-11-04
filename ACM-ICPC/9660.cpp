//
// Created by null on 11/3/17.
//

#include <cstdio>

using namespace std;

typedef unsigned long long UNLLONG;

int main() {
    UNLLONG n;

    scanf("%lld", &n);

    if ((n % 7 == 0) || (n % 7 == 2)) {
        printf("CY\n");
    } else {
        printf("SK\n");
    }
}