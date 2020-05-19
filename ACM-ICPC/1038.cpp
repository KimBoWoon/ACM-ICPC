#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LLONG;

int n;
vector<LLONG> v;

int main(void) {
	for (int i = 1; i <= 1023; i++) { // {0, 1, 2, 3, .. , 9}의 공집합이 아닌 부분집합을 뽑아내기 위해서.
		LLONG num = 0; // i에 대응되는 감소하는 수
		int j = i;

		for (int idx = 9; idx >= 0; idx--) {
			if (j % 2 == 1) {
				num = 10 * num + idx; // idx를 1의 자리에 넣음
            }

			j /= 2;

			if (j == 0) {
				break;
			}
		}

		v.push_back(num); // i에 대응되는 감소하는 수를 list에 넣음
	}

	sort(v.begin(), v.end());

	scanf("%d", &n);

	if (n > 1022) {
		printf("-1\n");
    } else {
		printf("%lld\n", v[n]);
    }

	return 0;
}