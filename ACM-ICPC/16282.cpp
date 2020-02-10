#include <cstdio>

long long n;

int main() {
    scanf("%lld", &n);

    long long answer = 0;
    
    while(answer + (answer + 1) * ((1LL << (answer + 1)) - 1) < n) {
        answer++;
    }
    
    printf("%lld\n", answer);
}