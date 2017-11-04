//
// Created by secret on 10/9/17.
//

#include <cstdio>
using namespace std;

char ans[200001];
int n, x, maxNum, sIdx, ansIdx;
int s[100001];

int main() {
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);

        // 해당하는 수까지 스택에 넣는다.
        if (x > maxNum) {
            for (int i = maxNum; i < x; i++) {
                s[sIdx++] = i + 1;
                ans[ansIdx++] = '+';
            }
        } else {
            // 스택의 최상위 값이 수열 값과 다르면 NO 출력
            if (s[sIdx - 1] != x) {
                printf("NO");
                return 0;
            }
        }
        // 해당하는 수가 나오면 팝한다.
        sIdx--;
        ans[ansIdx++] = '-';
        if (maxNum < x) {
            maxNum = x;
        }
    }

    for (int i = 0; i < ansIdx; i++) {
        printf("%c\n", ans[i]);
    }
}