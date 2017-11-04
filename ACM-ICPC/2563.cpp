//
// Created by null on 11/1/17.
//

#define LOCAL

#include <cstdio>

int n, a, b, ans;
int map[101][101];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);

        // 색종이가 덮인곳을 체크한다
        for (int x = a; x < a + 10; x++) {
            for (int y = b; y < b + 10; y++) {
                map[x][y] = 1;
            }
        }
    }

    // 색종이가 덮인 곳을 ans에 더해준다
    // 이것이 면적이 된다
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j]) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}