#include <cstdio>
#include <cmath>
using namespace std;
#define MOD 16769023

int n, answer = 1;

/*
균형잡힌 문자열이 첫 문자를 포함한 모든 부분문자열에 대해 적용되는 경우를 자세히 살펴보면 규칙을 찾을 수 있다.

n == 1 or 2 : 2가지  
n == 3 or 4 : 4가지  
n == 5 or 6 : 8가지
...
이렇게 나오는 이유는 간단하다. 길이가 홀수가 되는 순간에는 0과 1이 모두 올 수 있지만 짝수 길이가 되는 때에는 0과 1 중 하나만 올 수 있다. 무슨말인가 하면..

n = 1일 때 0 혹은 1만 가능하다.  
n = 2일 때 0에서 가능한 경우는 00과 01중 01만 가능하다.  
n = 3일 때 01에서 가능한 경우는 010, 011 모두 가능하다. 마찬가지로 10에서 가능한 경우는 101, 100 모두 가능하다.  
이걸 일반화 해보면 n이 짝수일 때 2의 n/2승, 홀수일때는 2의 n/2+1승개다.
참고 : https://sihyungyou.github.io/acmicpc2019-B/
*/

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n / 2; i++) {
        answer *= 2;
        answer %= MOD;
    }

    if (n % 2 != 0) {
        answer *= 2;
    }

    printf("%d\n", answer % MOD);

    return 0;
}