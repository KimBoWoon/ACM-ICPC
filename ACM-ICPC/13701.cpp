#include <cstdio>
using namespace std;

int n;
int arr[1 << 20];

/*
비트연산을 사용하는 문제
n / 32 : 자리
n % 32 : 바트
*/

int main() {
    while (scanf("%d", &n) != EOF) {
        int x = n / 32;
        int y = n % 32;

        if (!(arr[x] & (1 << y))) {
            printf("%d ", n);
            arr[x] |= 1 << y;
        }
    }
}