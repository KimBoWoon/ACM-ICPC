#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);

	if (n == 1) { // 세로가 1일 때는 움직을 수 없다. 하지만 시작위치까지 움직였다 생각하므로 1이다
		printf("1\n");
		return 0;
	}
	if (n == 2) { // 세로가 2일 때는 2, 3번 조건만 사용할 수 있기 때문에 최대 3회 움직일 수 있다
		printf("%d\n", min(4, (m + 1) / 2));
		return 0;
	}
	if (m < 7) { // 가로가 6이하면 최대 4칸 이동가능 
		printf("%d\n", min(4, m));
		return 0;
	}

	// 4회 이상 이동할 경우 모든 방법을 다 사용
	// 2, 번 경우에 2칸 씩 오른쪽으로 이동
	// 그러므로 한칸 씩은 손해를본다
	printf("%d\n", m - 2);
	return 0;
}