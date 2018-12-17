#include <iostream>
using namespace std;

char board[101][101];
int n, row, col;

int main() {
	cin >> n;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y];
		}
		board[x][n] = 'X';
		board[n][x] = 'X';
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n - 1; y++) {
			row += (board[x][y] == '.' && board[x][y + 1] == '.' && board[x][y + 2] == 'X') ? 1 : 0;
			col += (board[y][x] == '.' && board[y + 1][x] == '.' && board[y + 2][x] == 'X') ? 1 : 0;
		}
	}

	cout << row << " " << col << endl;
}