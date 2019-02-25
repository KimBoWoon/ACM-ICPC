#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ULLONG;

int k;
char arr[10];
bool visited[10];
vector<ULLONG> answer;

void dfs(int v, int cnt, ULLONG result) {
    if (cnt == k) {
        answer.push_back(result);
    } else {
        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                if (arr[cnt] == '<') {
                    if (v >= i) {
                        continue;
                    }
                } else {
                    if (v <= i) {
                            continue;
                    }
                }
                visited[i] = true;
                dfs(i, cnt + 1, result * 10 + i);
            }
        }
    }
    visited[v] = false;
}

int main() {
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%s", arr + i);
    }

    for (int i = 0; i < 10; i++) {
        visited[i] = true;
        dfs(i, 0, i);
    }

    printf("%lld\n", answer[answer.size() - 1]);
    if (answer[0] < pow(10, k)) {
        printf("0%lld\n", answer[0]);
    } else {
        printf("%lld\n", answer[0]);
    }
}