#include <cstdio>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    for (int i = 666, idx = 1; i < 2700000; i++) {
        int count = 0, temp = i;

        while (temp > 0) {
            if (temp % 10 == 6) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                if (n == idx) {
                    printf("%d\n", i);
                    return 0;
                } else {
                    idx++;
                }
            }
            temp /= 10;
        }
    }
}