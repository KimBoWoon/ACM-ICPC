//
// Created by secret on 1/4/17.
//

#include <cstdio>
using namespace std;

#pragma warning(disable:4996)

int map[501][501];
int d[2] = { 1, -1 };
int m, n;

int dp(int x, int y)
{
    int ans = 0;
	int tX, tY;

    if (x == m && y == n)
        return 1;

    for (int i = 0; i < 2; i++)
	{
		tX = x + d[i];
		tY = y + d[i];

		if (tX <= m && tX >= 1 && map[tX][y] < map[x][y])
			ans += dp(x + d[i], y);

		if (tY <= n && tY >= 1 && map[x][tY] < map[x][y])
			ans += dp(x, y + d[i]);
    }

    return ans;
}

int main()
{
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    printf("%d\n", dp(1, 1));
}