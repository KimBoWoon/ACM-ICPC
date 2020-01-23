#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

int n, m, answer;
int hacking[10001];
// vector<int> visited;
int visited[10001];
vector<int> computer[10001];

void dfs(int s) {
    hacking[s]++;
    if (answer < hacking[s]) {
        answer = hacking[s];
    }
    for (int i = 0; i < computer[s].size(); i++) {
        if (!visited[computer[s][i]]) {
            visited[computer[s][i]] = true;
            dfs(computer[s][i]);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        computer[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        // visited = vector<int>(n + 1, 0);
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        if (hacking[i] == answer) {
            printf("%d ", i);
        }
    }
    printf("\n");
}