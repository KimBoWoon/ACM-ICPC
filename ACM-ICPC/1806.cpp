#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, answer = 2e9;
int arr[100001];

int main() {
    scanf("%d %d", &n, &s);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = arr[i - 1] + x;
    }

    int x = 0, y = 0;
    while (y <= n) {
        int sum = arr[y] - arr[x];

        if (sum < s) {
            y++;
        } else if (sum >= s) {
            answer = min(answer, y - x);
            x++;
        }
    }

    if (answer == 2e9) {
        printf("0\n");
    } else {
        printf("%d\n", answer);
    }
}