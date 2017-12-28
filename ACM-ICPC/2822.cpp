//
// Created by null on 11/6/17.
//

#define LOCAL

#include<cstdio>

int n, sum, score[151], idx[9];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    // 인덱스 별로 점수를 표시한다
    for (int i = 0; i < 8; i++) {
        scanf("%d", &n);
        score[n] = i + 1;
    }

    // 포문을 반대로 돌리면서 가장 큰 값을 알아낸다
    // sum은 합계
    // idx은 선택받은 점수의 인덱스를 저장
    for (int i = 150, j = 0; i >= 0 && j < 5; i--) {
        if (score[i]) {
            sum += i;
            idx[score[i]] = i;
            j++;
        }
    }

    printf("%d\n", sum);

    for (int i = 0; i < 9; i++) {
        if (idx[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}