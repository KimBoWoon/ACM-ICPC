#include <cstdio>
using namespace std;

int x, y, day;
int m[13];
char *d[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    scanf("%d %d", &x, &y);

    m[1] = m[3] = m[5] = m[7] = m[8] = m[10] = m[12] = 31;
    m[4] = m[6] = m[9] = m[11] = 30;
    m[2] = 28;

    for (int i = 1; i < x; i++) {
        day += m[i];
    }

    day += y;

    printf("%s\n", d[day % 7]);
}

// 달에 있는 날짜와 남은 날짜를 모두 더해준 뒤
// 7로 나눈 나머지값을 출력