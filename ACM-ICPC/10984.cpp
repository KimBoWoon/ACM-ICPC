//
// Created by null on 11/8/17.
//

#define LOCAL

#include <cstdio>

int t, n, c;
double g;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int sum = 0;
        double grade = 0.0;

        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d %lf", &c, &g);
            sum += c;
            // 수강 학점 * 수여 받은 학점 결과 = 점수
            grade += c * g;
        }

        // 평균 평점 = 총 평점 / 총수강학점
        printf("%d %.1f\n", sum, grade / sum);
    }
}