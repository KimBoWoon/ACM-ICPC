#include <cstdio>
#include <vector>
using namespace std;

int k;
int s[13], result[6];

void dfs(int start, int depth) {
    if (depth == 6) { // 숫자 6개를 선택했을 때
        for (int i = 0; i < 6; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i < k; i++) { // 숫자 선택
        result[depth] = s[i];
        dfs(i + 1, depth + 1);
    }
}

int main() {
    while (scanf("%d", &k) && k) {
        for (int i = 0; i < k; i++) {
            scanf("%d", &s[i]);
        }
        
        dfs(0, 0);
        
        printf("\n");
    }
}
