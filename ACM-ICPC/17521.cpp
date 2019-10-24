#include <cstdio>
using namespace std;

long long int n, w, coin, low, hi;
int graph[16];
bool flag = false;

int main() {
    scanf("%lld %lld", &n, &w);

    for (int i = 0; i < n; i++) {
        scanf("%d", &graph[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (graph[i] < graph[i + 1]) {
            w = w % graph[i] + w / graph[i] * graph[i + 1];
        }
    }

    printf("%lld\n", w);

    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &graph[i]);
    // }

    // low = graph[0];

    // for (int i = 1; i < n; i++) {
    //     if (low < graph[i]) {
    //         hi = graph[i];
    //         ++i;
    //         for (i; hi < graph[i] && i < n; i++) {
    //             hi = graph[i];
    //         }
    //         w = (w / low) * hi + w % low;
    //     }
    //     low = graph[i];
    // }

    // printf("%lld\n", w);

    // low = graph[0];
    // for (int i = 1; i < n; i++) {
    //     if (low > graph[i]) {
    //         low = graph[i];
    //     } else if (low < graph[i] && !flag) {
    //         coin = w / low;
    //         w %= low;
    //         hi = graph[i];
    //         flag = true;
    //     } else if (hi < graph[i]) {
    //         hi = graph[i];
    //     } else if (hi > graph[i] && flag) {
    //         w += coin * hi;
    //         coin = 0;
    //         low = graph[i];
    //         flag = false;
    //     }
    // }

    // printf("%lld\n", coin * graph[n - 1] + w);
}