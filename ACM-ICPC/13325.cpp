#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

#define MAXN (1 << 21)

//int K, N;
//int A[MAXN], D[MAXN], L[MAXN];
//
//int main() {
//	scanf("%d", &K);
//	N = (1 << (K + 1)) - 1;
//
//	for (int i = 2; i <= N; i++) {
//		scanf("%d", A + i);
//	}
//
//	for (int i = (1 << K); --i;) {
//		L[i] = max(L[i + i] + A[i + i], L[i + i + 1] + A[i + i + 1]);
//		D[i] = D[i + i] + D[i + i + 1] + L[i] - L[i + i] + L[i] - L[i + i + 1];
//	}
//
//	printf("%d\n", D[1]);
//}

#define INF 987654321

typedef long long lld;

int n;
int a[(1 << 21) + 1];

int leftPos(int pos) {
	return 2 * pos + 1;
}
int rightPos(int pos) {
	return leftPos(pos) + 1;
}

int f(int pos) {
	int l = leftPos(pos), r = rightPos(pos);
	// is leaf
	if (l > n || r > n) {
		return a[pos];
	}

	int lsum = f(l), rsum = f(r);
	if (lsum < rsum) {
		a[l] += rsum - lsum;
	}
	else if (lsum > rsum) {
		a[r] += lsum - rsum;
	}

	return a[pos] + max(lsum, rsum);
}

int main(){
	int k;

	scanf("%d", &k);

	n = (1 << (k + 1)) - 1 - 1;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	f(0);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i];
	}

	printf("%d\n", ans);

	return 0;
}