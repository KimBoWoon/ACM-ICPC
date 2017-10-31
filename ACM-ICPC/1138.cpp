#define LOCAL

#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable: 4996)

#define INF 999999999

int n;
pair<int, int> line[11];

void permutations(pair<int, int> *line, const int k, const int m) {
	if (k == m) {//순열이 완성됐을 때 한 줄로 서기 검사
		bool chk = false;
		for (int i = 0; i <= m; i++) {
			int front = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (line[i].first < line[j].first) {
					front++;
				}
			}
			if (front == line[i].second) {
				chk = true;
			}
			else {
				chk = false;
				break;
			}
		}
		if (chk)
		{
			for (int i = 0; i <= m; i++) {
				printf("%d ", line[i].first);
			}
			printf("\n");
			exit(0);
		}
	}
	else {
		for (int i = k; i <= m; i++) {
			swap(line[k], line[i]);
			permutations(line, k + 1, m);
			swap(line[k], line[i]);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		line[i] = { i + 1, x };
	}

	permutations(line, 0, n - 1);
}