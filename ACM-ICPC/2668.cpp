#include <cstdio>
#include <cstring>
using namespace std;

int n, answer;
int arr[101];
bool visited[101], cycle[101];

bool dfs(int start, int cur) {
    if (visited[cur]) {
        return false;
    }
	
    visited[cur] = true;

	if (start == cur || dfs(start, arr[cur])) { // 사이클을 이룰 때, 사이클을 이루는 모든 숫자들을 참으로 설정
        answer++;
        cycle[cur] = true;
        return true;
    }

    return false;
}

int main() {
	scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { // 사이클을 이룬 숫자들을 모두 방문 했다고 표시
            visited[j] = cycle[j];
        }
        dfs(i, arr[i]);
    }

    printf("%d\n", answer);
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            printf("%d\n", i);
        }
    }
}