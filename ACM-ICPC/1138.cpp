// #include <cstdio>
// #include <algorithm>
// using namespace std;

// #define INF 999999999

// int n;
// pair<int, int> line[11];

// void permutations(pair<int, int> *line, const int k, const int m) {
// 	if (k == m) {//순열이 완성됐을 때 한 줄로 서기 검사
// 		bool chk = false;
// 		for (int i = 0; i <= m; i++) {
// 			int front = 0;
// 			for (int j = i - 1; j >= 0; j--) {
// 				if (line[i].first < line[j].first) {
// 					front++;
// 				}
// 			}
// 			if (front == line[i].second) {
// 				chk = true;
// 			}
// 			else {
// 				chk = false;
// 				break;
// 			}
// 		}
// 		if (chk) {
// 			for (int i = 0; i <= m; i++) {
// 				printf("%d ", line[i].first);
// 			}
// 			printf("\n");
// 			exit(0);
// 		}
// 	}
// 	else {
// 		for (int i = k; i <= m; i++) {
// 			swap(line[k], line[i]);
// 			permutations(line, k + 1, m);
// 			swap(line[k], line[i]);
// 		}
// 	}
// }

// int main() {
// 	scanf("%d", &n);

// 	for (int i = 0; i < n; i++) {
// 		int x;
// 		scanf("%d", &x);
// 		line[i] = { i + 1, x };
// 	}

// 	permutations(line, 0, n - 1);
// }

#include <cstdio>
using namespace std;

int n;
int line[11];

/*
left가 자신이 들어가야할 위치
line[j] == 0 이면 사람이 없음을 표시
left를 줄여가면서 사람이 없으면 넣어준다
*/

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int left;

		scanf("%d", &left);

		for (int j = 0; j < n; j++) {
			if (left == 0 && line[j] == 0) {
				line[j] = i + 1;
				break;
			} else if (line[j] == 0) {
				left--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", line[i]);
	}
	printf("\n");
}