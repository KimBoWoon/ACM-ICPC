#include <cstdio>

int E, S, M, e, s, m, ans;

int main() {
	scanf("%d %d %d", &E, &S, &M);

	while (++ans) {
		if (E == e && S == s && M == m) {
			break;
		}

		e = (e % 15) + 1;
		s = (s % 28) + 1;
		m = (m % 19) + 1;
	}

	printf("%d\n", ans - 1);
}