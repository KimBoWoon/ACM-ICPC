#include <cstdio>
using namespace std;

#define SIZE 1000001
bool prime[SIZE];

void eratos() {
	for (int i = 2; i <= SIZE; i++) {
		prime[i] = true;
	}

	for (int i = 2; (i * i) <= SIZE; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= SIZE; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
    eratos();

    while (true) {
        int x;
        bool flag = false;

        scanf("%d", &x);

        if (x == 0) {
            return 0;
        }

        for (int i = 0; i < x; i++) {
            if (prime[i] && prime[x - i]) {
                printf("%d = %d + %d\n", x, i, x - i);
                flag = true;
                break;
            }
        }

        if (!flag) {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}