#include <bits/stdc++.h>

int t, n;
int arr[41] = {1, 1};

int topDown(int x) {
    if (x <= 1) {
        return arr[x];
    } else {
        if (arr[x] > 0) {
            return arr[x];
        }
    }
    
    return arr[x] = topDown(x - 1) + topDown(x - 2);
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        
        if (n == 0) {
            printf("1 0\n");
        } else if (n == 1) {
            printf("0 1\n");
        } else {
            topDown(n);
            printf("%d %d\n", arr[n - 2], arr[n - 1]);
        }
    }
}