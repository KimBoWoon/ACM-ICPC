//
// Created by null on 11/7/17.
//

#include <cstdio>
#include <cmath>

double r;

int main() {
    scanf("%lf", &r);

    // pi * r ^ 2
    printf("%0.6f\n", M_PI * r * r);
    // 택시 기하학은 원이 정사각형이다 그래서 정사각형의 넓이가 곧 원의 넓이다
    // 반지름이 주어지고 r * 2면 지름이고 지름이 대각선의 길이이다
    // 대각선의 길이 : 한변의 길이(a) * √2
    // 2r = √2 * a => 4r^2 = 2a^2 => 2r^2 = a^2
    // r * r * 2
    printf("%0.6f\n", 2 * r * r);
}