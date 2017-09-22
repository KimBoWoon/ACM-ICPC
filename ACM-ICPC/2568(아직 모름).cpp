#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
pair<int, int> p[101];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
	}

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].first, p[i].second);
	}

	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back(p[i].second);
		}
		else if (v[v.size() - 1] > p[i].second) {
			vector<int>::iterator idx = lower_bound(v.begin(), v.end(), p[i].second);
			*idx = p[i].second;
		}
		else if (v[v.size() - 1] < p[i].second) {
			v.push_back(p[i].second);
		}
	}

	printf("%d\n", n - v.size());

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", p[i].first, p[i].second);
	}
}

//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//const int MXN = 1e5, MXI = 5e5;
//pair<int, int> p[MXN];
//int n, sz, dp[MXN], fr[MXI + 1], ck[MXI + 1];
//
//int main() {
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &p[i].first, &p[i].second);
//	}
//
//	sort(p, p + n);
//
//	for (int i = 0; i < n; i++) {
//		int h = lower_bound(dp, dp + sz, p[i].second) - dp;
//
//		if (h == sz) {
//			sz++;
//		}
//
//		dp[h] = p[i].second;
//		fr[dp[h]] = h ? dp[h - 1] : 0;
//	}
//
//	printf("%d\n", n - sz);
//
//	for (int i = dp[sz - 1]; i; i = fr[i]) {
//		ck[i] = 1;
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (!ck[p[i].second]) {
//			printf("%d\n", p[i].first);
//		}
//	}
//	return 0;
//}