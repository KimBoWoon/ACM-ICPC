#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 4000000

int n, answer;
bool prime[4000001];
int subSum[4000001];

void eratos() {
	// 모두 true로 초기화
	// 소수 여부에 따라 값을 변화
	for (int i = 2; i <= MAX; i++) {
		prime[i] = true;
	}

	// 에라토스테네스의 소수 구하기 알고리즘
	// 1. 2부터 시작, 2는 소수로 체크 하고
	// 2. 2의 배수는 모두 false로 체크 (2의 배수는 2로 나눠지기 때문)
	// 3. 다음 숫자인 3도 1 ~ 2를 수행
	// 4. 다음 숫자인 4는 2의 배수이므로 다음으로 넘어간다.
	for (int i = 2; (i * i) <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	// 소수 구하기
	eratos();

	// 구해진 소수들의 부분합 구하기
	// 매번 해당하는 구간 마다 반복해서 답을 구하는 것 보다
	// 뺄샘 한번으로 해당 구간의 합을 구할 수 있기 때문에 빠르다
	subSum[0] = 0;
    subSum[1] = 2;
    for (int i = 3, idx = 2; i < MAX; i++) {
        if (prime[i]) {
            subSum[idx++] = subSum[idx - 1] + i;
        }
    }

	// 투포인터 사용
	int x = 0, y = 1;

	// x가 y값 보다 작을 때 반복 수행
	while (x < y) {
		if (subSum[y] - subSum[x] < n) { // 구간합이 작을 때 y를 늘림
			y++;
		} else if (subSum[y] - subSum[x] > n) { // 구간합이 클 때 x를 늘림
			x++;
		} else if (subSum[y] - subSum[x] == n) { // 구간합과 같을 때 정답표시 한 뒤 x를 늘림
			answer++;
			x++;
		}
	}

	printf("%d\n", answer);
}