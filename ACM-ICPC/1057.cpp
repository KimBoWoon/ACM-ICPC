#include <cstdio>

int n, x, y;

int main() {
    scanf("%d %d %d", &n, &x, &y);
    
    for (int i = 1; x != y; i++) {
        x = x / 2 + x % 2;
        y = y / 2 + y % 2;
        
        if (x == y) {
            printf("%d\n", i);
            break;
        }
    }
}
