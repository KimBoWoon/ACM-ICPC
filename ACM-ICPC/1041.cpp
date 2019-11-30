#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLONG;

LLONG n;
LLONG dice[6];
LLONG side3, side2, side1, answer;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice[i]);
    }

    side1 = 4 * (n - 1) * (n - 2) + (n - 2) * (n - 2);
    side2 = 4 * (n - 1) + 4 * (n - 2);
    side3 = 4;

    if (n == 1) {
        sort(dice, dice + 6);

        for (int i = 0; i < 5; i++) {
            answer += dice[i];
        }
    } else {
        dice[0] = (dice[0] < dice[5]) ? dice[0] : dice[5];
        dice[1] = (dice[1] < dice[4]) ? dice[1] : dice[4];
        dice[2] = (dice[2] < dice[3]) ? dice[2] : dice[3];

        sort(dice, dice + 3);

        LLONG min[3] = {
            dice[0],
            dice[0] + dice[1],
            dice[0] + dice[1] + dice[2]
        };

        answer = (min[0] * side1) + (min[1] * side2) + (min[2] * side3);
    }

    printf("%lld\n", answer);
}