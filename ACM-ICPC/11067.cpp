#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100005

int T, N, M;

struct Z{
	int x, y, o;
} A[MAXN];

bool compXY(const Z &x, const Z &y) {
	return (x.x != y.x) ?
		x.x < y.x :
		x.y < y.y;
}

bool compN(const Z &x, const Z &y) {
	return x.o < y.o;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	for (scanf("%d", &T); T--;){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &A[i].x, &A[i].y);
		sort(A + 1, A + N + 1, compXY);
		int last_y = 0, o = 1;
		for (int i = 1; i <= N; i++){
			int t = i;
			for (int j = i + 1; j <= N; j++){
				if (A[j].x == A[i].x) t = j;
				else break;
			}
			if (A[i].y < last_y && last_y < A[t].y)
				for (;;);
			else if (A[i].y >= last_y){
				for (int j = i; j <= t; j++)
					A[j].o = o++;
				last_y = A[t].y;
			}
			else{
				for (int j = t; j >= i; j--)
					A[j].o = o++;
				last_y = A[i].y;
			}
			i = t;
		}
		sort(A + 1, A + N + 1, compN);
		for (scanf("%d", &M); M--;){
			int n; scanf("%d", &n);
			printf("%d %d\n", A[n].x, A[n].y);
		}
	}
}