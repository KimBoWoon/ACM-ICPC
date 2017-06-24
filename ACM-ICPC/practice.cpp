//
// Created by secret on 6/24/17.
//

#include <cstdio>

int main() {
    for (int i = 1; i <= 16; i += i & -i) {
        printf("%d\n", i);
    }
}