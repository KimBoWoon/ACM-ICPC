#include <bits/stdc++.h>

int n;

int main() {
    while (true) {
        int answer = 0;

        scanf("%d", &n);

        if (n == 0) {
            return 0;
        }

        int sqrtNum = sqrt(n);

        for (int i = 1; i <= sqrtNum; i++) {
            if (i * i == n) {
                answer++;
                continue;
            }
            for (int j = i; j <= sqrtNum; j++) {
                if (i * i + j * j == n) {
                    answer++;
                    break;
                } else if (i * i + j * j > n) {
                    break;
                }
                for (int k = j; k <= sqrtNum; k++) {
                    if (i * i + j * j + k * k == n) {
                        answer++;
                        break;
                    } else if (i * i + j * j + k * k > n) {
                        break;
                    }
                    for (int l = k; l <= sqrtNum; l++) {
                        if (i * i + j * j + k * k + l * l == n) {
                            answer++;
                            break;
                        } else if (i * i + j * j + k * k + l * l > n) {
                            break;
                        }
                    }
                }
            }
        }

        printf("%d\n", answer);
    }
}