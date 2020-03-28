#include <cstdio>
#include <vector>
using namespace std;

int n, l;
vector<int> v;

int main() {
    scanf("%d %d", &n, &l);

    for (int i = l; i <= 100; i++) {
        int temp = n - i * (i + 1) / 2;

        if (temp % i == 0) {
            int j = temp / i + 1;

            if (j >= 0) {
                for (int k = 0; k < i; k++) {
                    printf("%d ", k + j);
                }
                printf("\n");

                return 0;
            }
        }
    }

    printf("-1\n");
}

// 참고
// https://danco.tistory.com/30
// 수학적 지식이 필요한 문제