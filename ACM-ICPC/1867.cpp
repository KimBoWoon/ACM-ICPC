#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 501

int n, k;
int visit[MAX], b[MAX];
vector<vector<int> > v;

// 최소 버텍스 커버를 구하는 문제
// 쾨닉의 정리의 따르면 최대 이분 매칭의 수가 답이 된다고 한다
// 아직 잘 모르겠다
bool dfs(int start) {
    if (visit[start]) {
        return false;
    }
    visit[start] = true;
    
    for (int i = 0; i < v[start].size(); i++) {
        if (!b[v[start][i]] || dfs(b[v[start][i]])) {
            b[v[start][i]] = start;
            return true;
        }
    }

    return false;
}

int bmatch() {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        memset(visit, 0, sizeof(visit));
        if (dfs(i)) {
            answer++;
        }
    }

    return answer;
}

int main() {
    scanf("%d %d", &n, &k);

    v.resize(n + 1);

    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        v[r].push_back(c);
    }

    printf("%d\n", bmatch());
}