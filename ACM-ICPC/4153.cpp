#include <cstdio>

int main() {
    while (true) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        if (x == 0 && y == 0 && z == 0) {
            return 0;
        }

        if ((x * x) + (y * y) == (z * z) || (y * y) + (z * z) == (x * x) || (x * x) + (z * z) == (y * y)) {
            printf("%s\n", "right");
        } else {
            printf("%s\n", "wrong");
        }
    }
}