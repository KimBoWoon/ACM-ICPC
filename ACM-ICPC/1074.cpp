#include <cstdio>

int n, r, c, cnt;

void f(int x, int y, int size) {
    if (size == 2) {
        if (x == r && y == c) {
            printf("%d\n", cnt);
            return;
        }
        cnt++;
        if (x == r && y + 1 == c) {
            printf("%d\n", cnt);
            return;
        }
        cnt++;
        if (x + 1 == r && y == c) {
            printf("%d\n", cnt);
            return;
        }
        cnt++;
        if (x + 1 == r && y + 1 == c) {
            printf("%d\n", cnt);
            return;
        }
        cnt++;
        return;
    }

    // 1사분면
    f(x, y, size / 2);
    // 2사분면
    f(x, y + size / 2, size / 2);
    // 3사분면
    f(x + size / 2, y, size / 2);
    // 4사분면
    f(x + size / 2, y + size / 2, size / 2);
}

int main() {
    scanf("%d %d %d", &n, &r, &c);

    f(0, 0, 1 << n);
}