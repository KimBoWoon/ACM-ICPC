#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int n, visit;
int map[16][16], dp[16][1 << 16];

int tsp(int cur, int stat) {
    // 모든 곳을 방문했으면
    if (stat == visit) {
        // 모든 곳을 순회할 수 없으면
        if (map[cur][0] == 0) {
            return 987654321;
        } else {
            // 처음 시작한 장소에 최소값이 저장되어있다
            return map[cur][0];
        }
    }

    int &ref = dp[cur][stat];
    // 0이 아니면 이미 최소값이 저장되어있다
    if (ref != 0) {
        return ref;
    }

    int m = INT_MAX - 16000001;
    // 다음 장소를 찾는다
    for (int i = 1; i < n; ++i) {
        // 현재 장소를 방문하지 않았고 map이 0이 아니면 이동할 수 있는 곳이다
        if (((stat & (1 << i)) == 0) && (map[cur][i] != 0)) {
            m = min(m, tsp(i, (stat | (1 << i))) + map[cur][i]);
        }
    }

    return ref = m;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    visit = (1 << n) - 1;
    printf("%d\n", tsp(0, 1));
}