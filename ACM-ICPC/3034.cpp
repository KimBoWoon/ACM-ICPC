//
// Created by null on 11/28/17.
//

#define LOCAL

#include <cstdio>

int n, w, h, x;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &w, &h);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        // 박스 크기의 가로 세로가 W, H라면, 최대 박스의 대각선 길이 이하인 성냥까지 박스에 들어갈 수 있다.
        printf((x * x > w * w + h * h) ? "NE\n" : "DA\n");
    }
}