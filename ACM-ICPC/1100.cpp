#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

char board[10][10];
int check1, check2, ans;

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1c", &board[i][j]);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'F' && check1 % 2 == 0) {
				ans++;
			}
			check1++;
		}
		check1++;
	}

	printf("%d\n", ans);
}