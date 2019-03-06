#include <cstdio>
#include <algorithm>
using namespace std;

int x, y;
int station[4];

int main() {
    // 조건에 맞게 실행하면 된다
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &x, &y);

        station[i] = station[i - 1] - x;
        station[i] = station[i] + y;
    }

    printf("%d\n", max(station[0], max(station[1], max(station[2], station[3]))));
}