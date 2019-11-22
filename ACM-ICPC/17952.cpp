#include <cstdio>
#include <stack>
using namespace std;

typedef struct Work {
    int score, time;
} work;

int n, x, a, t, answer;
stack<work> s;

int main() {
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);

        if (x == 1) {
            scanf("%d %d", &a, &t);

            s.push({a, --t});
        } else {
            if (!s.empty()) {
                s.top().time--;
            }
        }

        if (!s.empty() && s.top().time == 0) {
            answer += s.top().score;
            s.pop();
        }
    }

    printf("%d\n", answer);
}