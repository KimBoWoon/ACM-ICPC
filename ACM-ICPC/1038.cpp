#include <bits/stdc++.h>

typedef long long LLONG;

int n;
std::vector<LLONG> v;

int main(void) {
	for (int i = 1; i <= 1023; i++) {
		LLONG num = 0;
		int tmp_i = i;

		for (int idx = 9; idx >= 0; idx--) {
			if (tmp_i % 2 == 1) {
				num = 10 * num + idx;
            }
			tmp_i /= 2;
		}
		v.push_back(num);
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