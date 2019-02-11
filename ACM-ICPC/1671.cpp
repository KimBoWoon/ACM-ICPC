#include <cstdio>
#include <vector>
using namespace std;

#define MAX_SIZE 51

typedef struct Shark {
    int size, speed, intel;
} shark;

shark sharks[MAX_SIZE];
int visit[MAX_SIZE], b[MAX_SIZE], n, cnt;
vector<int> v[MAX_SIZE];

int dfs(int k) {
    if (visit[k]) {
        return 0;
    }

    visit[k] = 1;

    for (int i = 0; i < v[k].size(); i++) {
        if (!b[v[k][i]] || dfs(b[v[k][i]])) {
            b[v[k][i]] = k;
            return 1;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &sharks[i].size, &sharks[i].speed, &sharks[i].intel);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (sharks[i].size >= sharks[j].size && sharks[i].speed >= sharks[j].speed && sharks[i].intel >= sharks[j].intel) {
                v[i].push_back(j);
            } else if (sharks[j].size >= sharks[i].size && sharks[j].speed >= sharks[i].speed && sharks[j].intel >= sharks[i].intel) {
                v[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(visit, visit + MAX_SIZE, 0);

        if (dfs(i)) {
            cnt++;
        }

        fill(visit, visit + MAX_SIZE, 0);

        if (dfs(i)) {
            cnt++;
        }
    }

    printf("%d\n", n - cnt);

    return 0;
}