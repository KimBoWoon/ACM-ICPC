#include <cstdio>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int temp = i, sum = 0;

        // 자릿수 합
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // 자릿수의 합과 i가 n과 같으면 결과 출력
        if (n == i + sum) {
            printf("%d\n", i);
            break;
        } else if (n == i) {
            printf("0\n");
            break;
        }
    }
}