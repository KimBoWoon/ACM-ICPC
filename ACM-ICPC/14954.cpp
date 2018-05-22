#include <cstdio>
#include <set>
using namespace std;

set<int> s;

int main() {
    int n, sum = 0;
    
    scanf("%d", &n);
    s.insert(n);
    
    while (1) {
        if (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
            continue;
        }
        n = sum;
        sum = 0;
        
        if (n == 1) {
            printf("HAPPY\n");
            return 0;
        } else if (s.find(n) != s.end()) {
            printf("UNHAPPY\n");
            return 0;
        }
        s.insert(n);
    }
}