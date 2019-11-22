#include <cstdio>
using namespace std;

int n, m, k, ans;

/*
대회에 참가할 수 있는 만큼 최대한 많은 팀을 만들고
나머지 인원들을 인턴으로 보낸다
그래도 인턴 인원이 충당되지 않으면
대회에 참가한 인원을 빼서 보낸다
남자 한명 여자 두명 이므로 3명씩 빼낸다
*/

int main() {
	scanf("%d %d %d", &n, &m, &k);

	while (n / 2 && m) {
		n -= 2;
		m--;
		ans++;
	}

	(m > 0) ? k -= m : 0;
	(n > 0) ? k -= n : 0;

	while (k > 0 && ans != 0) {
		ans--;
		k -= 3;
	}

	printf("%d\n", ans);
}