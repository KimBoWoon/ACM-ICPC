#include <cstdio>
#include <vector>
using namespace std;

int k;
int s[13], result[6];

void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i < k; i++) {
        result[depth] = s[i];
        dfs(i + 1, depth + 1);
    }
}

int main() {
    while (scanf("%d", &k) && k) {
        for (int i = 0; i < k; i++) {
            int x = 0;
            scanf("%d", &x);
            s[i] = x;
        }
        
        dfs(0, 0);
        
        printf("\n");
    }
}
