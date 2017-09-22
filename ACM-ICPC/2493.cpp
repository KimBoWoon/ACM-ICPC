#include <cstdio>
#include <stack>

using namespace std;

#pragma warning(disable:4996)

typedef struct top {
    int index, height;
} Top;

int main() {
    int n = 0;
    stack<Top> s;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;

        scanf("%d", &temp);

        while (true) {
            if (s.empty()) {
                printf("0 ");
                s.push({i + 1, temp});
                break;
            } else if (s.top().height > temp) {
                printf("%d ", s.top().index);
                s.push({i + 1, temp});
                break;
            } else {
                s.pop();
            }
        }
    }

    return 0;
}