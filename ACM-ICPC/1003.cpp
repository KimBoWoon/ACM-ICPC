#include <cstdio>
using namespace std;

int arr[41] = {1, 1};

int fibonacci(int n) {
    if (n <= 1) {
        return arr[n];
    } else {
        if (arr[n] > 0) {
                return arr[n];
        }
    }
    
    return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int testCase;
    
    scanf("%d", &testCase);
    
    while (testCase--) {
        int n;
        
        scanf("%d", &n);
        
        if (n == 0) {
            printf("1 0\n");
        } else if (n == 1) {
            printf("0 1\n");
        } else {
            fibonacci(n);
            printf("%d %d\n", arr[n - 2], arr[n - 1]);
        }
    }
}