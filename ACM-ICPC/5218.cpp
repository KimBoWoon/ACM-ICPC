#include <cstdio>
#include <cstring>
using namespace std;

int n, len;
char str1[21], str2[21];

int main() {
    scanf("%d", &n);

    while (n--) {
        scanf("%s %s", str1, str2);

        len = strlen(str1);

        // 문제에서 요구하는 식을 알맞게 구성하면 된다
        // 문제 : 'A'=1, 'B' = 2, ..., 'Z' = 26. 그 다음 y ≥ x인 경우에는 y-x, y < x인 경우에는 (y+26) - x가 알파벳 거리가 된다.
        printf("Distances: ");
        for (int i = 0; i < len; i++) {
            if (str2[i] >= str1[i]) {
                printf("%d ", str2[i] - str1[i]);
            } else if (str2[i] < str1[i]) {
                printf("%d ", (str2[i] + 26) - str1[i]);
            }
        }
        printf("\n");
    }
}