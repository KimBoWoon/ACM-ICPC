#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, answer = 987654321;
int arr[21][21];
bool visited[21];

void f(int idx, int temp) {
    // n은 무조건 짝수 이므로
    // temp == n / 2면 팀선택 완료
    if (n / 2 == temp) {
        int x = 0, y = 0;
        vector<int> start, link;
        
        // visited값에 따라 팀 분배
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                start.push_back(i);
            } else {
                link.push_back(i);
            }
        }

        // 팀 능력치 합산
        for (int i = 0; i < start.size(); i++) {
            for (int j = i + 1; j < start.size(); j++) {
                x += arr[start[i]][start[j]] + arr[start[j]][start[i]];
                y += arr[link[i]][link[j]] + arr[link[j]][link[i]];
            }
        }

        // 차이값이 작은 값이 정답
        answer = (answer > abs(x - y)) ? abs(x - y) : answer;
        return;
    }

    for (int i = idx + 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            f(i, temp + 1);
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    f(0, 0);

    printf("%d\n", answer);
}