#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1000001 

int f, s, g, u, d;
int building[MAX];
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        int next = here + u;
        if (next <= f && building[next] == 0) {
            building[next] = building[here] + 1;
            q.push(next);
        }

        next = here - d;
        if (next > 0 && building[next] == 0) {
            building[next] = building[here] + 1;
            q.push(next);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    building[s] = true;
    q.push(s);

    bfs();

    if (building[g]) {
        printf("%d\n", building[g] - 1);
    } else {
        printf("use the stairs\n");
    }
}