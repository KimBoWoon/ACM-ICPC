#define LOCAL

#include <cstdio>

int n, m;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &m);

	// (m + 15) / 60 �� 60���� �� �� �ð� �ø��� ��
	// 24 �ð��� �̱� ������ 23�� �����ش�
	printf("%d %d\n", (n + 23 + (m + 15) / 60) % 24, (m + 15) % 60);
}