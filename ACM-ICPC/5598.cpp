//
// Created by secret on 9/30/17.
//

#include <cstdio>

char str[1001];

int main() {
    scanf("%s", str);

    for (int i = 0; str[i] != 0; i++) {
        str[i] = (str[i] + 10) % 26 + 65;
    }

    printf("%s\n", str);
}