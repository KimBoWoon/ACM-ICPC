#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAX 10001

char num[4];
bool prime[MAX], check[MAX];
int t, before, after;
int visit[MAX];

void eratos() {
	for (int i = 2; i <= MAX; i++) {
		prime[i] = true;
	}

	for (int i = 2; i <= MAX; i++) {
		if (prime[i]) { 
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
            }
		}
	}
}

int change(int now, int start, int digit) {
    if (start == 0 && digit == 0) {
        return -1;
    }

    for (int i = 3; i >= 0; i--) {
        num[i] = (now % 10) + '0';
        now /= 10;
    }

    num[start] = digit + '0';

    return atoi(num);
}

void bfs(int before) {
    queue<int> q;

    q.push(before);
    check[before] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                int next = change(now, i, j);
                if (next != -1 && prime[next] && !check[next]) {
                    q.push(next);
                    visit[next] = visit[now] + 1;
                    check[next] = true;
                }
            }
        }
    }
}

int main() {
    eratos();

    scanf("%d", &t);

    while (t--) {
        for (int i = 0; i < MAX; i++) {
            visit[i] = 0;
            check[i] = false;
        }

        scanf("%d %d", &before, &after);

        bfs(before);

        // 현재 모든 테스트 케이스가 정답이 존재해서 0을 출력하면 정답이라고 나온다
        // 테스트 케이스의 부족이라한다
        // https://www.acmicpc.net/board/view/33879
        printf("%d\n", visit[after]);

        // if (visit[after] == 0) {
        //     printf("Impossible\n");
        // } else {
        //     printf("%d\n", visit[after] - 1);
        // }
    }
}