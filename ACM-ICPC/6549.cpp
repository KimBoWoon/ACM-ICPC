#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int n;
int height[100001];
stack<int> s;

int main() {
	while (true) {
		scanf("%d", &n);

		if (n == 0) {
			return 0;
		}

		memset(height, 0, sizeof(int) * 100001);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &height[i]);
		}

		int now = 0;
		long long ans = 0;
		s.push(0);

		for (int i = 1; i <= n + 1; i++) {
			while (true) {
				if (s.size() == 0) {
					break;
				}
				int x = s.top();
				if (height[x] < height[i]) {
					break;
				}
				s.pop();
				if (s.size() > 0) {
					long long area = (long long)height[x] * (long long)(now - s.top());
					if (area > ans) {
						ans = area;
					}
				}
			}
			s.push(i);
			now++;
		}
		printf("%lld\n", ans);
	}
}