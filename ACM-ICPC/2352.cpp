#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;
vector<int> v;

int main() {
	scanf("%d", &n);

	v.resize(n, 0);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++) {
		vector<int>::iterator iter = lower_bound(v.begin(), v.begin() + answer, v[i]); // v[i]를 범위내에서 찾는다

		if (iter == (v.begin() + answer)) { // 찾아낸 값이 마지막 값과 같으면 교차되지 않고 연결할 수 있는 선이다
			answer++;
		}

		*iter = v[i]; // 다음 LIS 비교를 위해 값 교체
	}

	printf("%d\n", answer);
}

// 직전에 사용한 값보다 현재들어온 값이 작으면 선이 교차된다
// 그러므로 문제는 LIS문제가 된다