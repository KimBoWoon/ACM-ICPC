//
// Created by null on 11/3/17.
//

#define LOCAL

#include <cstdio>
#include <algorithm>

#define MAXN 247000

using namespace std;
int n, ans;
bool prime[MAXN];

void eratos() {
    for(int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    fill(prime, prime + MAXN, true);

    eratos();

    scanf("%d", &n);

    while (n != 0) {
        ans = 0;

        for (int i = n + 1; i <= n * 2; i++) {
            if (prime[i]) {
                ans++;
            }
        }

        printf("%d\n", ans);

        scanf("%d", &n);
    }
}