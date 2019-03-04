#include <cstdio>
using namespace std;

#define MAX 1299780

int t, k, start, end;
bool prime[MAX], flag1, flag2;

void eratos() {
	for (int i = 2; i <= MAX; i++) {
		prime[i] = true;
	}

	for (int i = 2; (i * i) <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
    // 소수가 필요하니 문제 입력에 나온 최대치 만큼 소수를 구한다
    eratos();

    scanf("%d", &t);

    while (t--) {
        start = end = 0;
        flag1 = flag2 = true;

        scanf("%d", &k);

        // k를 포함해야 하니 i는 감소, j는 증가를 시키며 근처의 소수를 찾는다
        // 찾으면 두 소수 사이의 길이이니 end - start를 해주면 답이 나온다
        for (int i = k, j = k; ; i--, j++) {
            if (prime[i] && flag1) {
                flag1 = false;
                start = i;
            }
            if (prime[j] && flag2) {
                flag2 = false;
                end = j;
            }

            if (!flag1 && !flag2) {
                printf("%d\n", end - start);
                break;
            }
        }
    }
}