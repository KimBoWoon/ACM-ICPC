#include <cstdio>
using namespace std;

int n, x;
char arr[101][101];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    scanf("%d", &x);

    if (x == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    } else if (x == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }
}