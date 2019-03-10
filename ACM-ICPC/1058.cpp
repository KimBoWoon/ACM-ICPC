#include <cstdio>
#include <algorithm>
using namespace std;

#define VERTICES 51
#define INF 987564231

int n, answer;
int arr[VERTICES][VERTICES], c[VERTICES][VERTICES];

// 플로이드를 사용하여 친구랑 친구의 친구 수만 구하면 된다
// 현재 정점에서 길이가 2 이하인 다른 정점들로 갈 때 총 몇가지인지 구하는데 이중 최대를 구하시오.
void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}

int main() {
    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            scanf(" %c", &temp);
            if (temp == 'N') {
                continue;
            }
            arr[i][j] = arr[j][i] = 1;
        }
    }

    floyd();

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] <= 2) {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }

    printf("%d\n", answer - 1);
}