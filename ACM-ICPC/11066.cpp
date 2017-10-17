//#include <iostream>
//#include <string.h>
//#include <algorithm>
//#include <climits>
//using namespace std;
//
//int mergeMatrix[501][501] = { 0 };
//int file[501] = { 0 };
//int sum[501] = { 0 };
//
//int main() {
//	int testCase;
//
//	cin >> testCase;
//
//	while (testCase--) {
//		int size;
//
//		cin >> size;
//
//		memset(file, 0, sizeof(int) * 501);
//		memset(sum, 0, sizeof(int) * 501);
//
//		for (int i = 0; i < size; i++) {
//			cin >> file[i];
//			sum[i + 1] = sum[i] + file[i];
//		}
//
//		for (int x = 1; x < size; x++) {
//			for (int y = 1; y <= size - x; y++) {
//				int j = y + x;
//				if (j > size)
//					break;
//				mergeMatrix[y][j] = INT_MAX;
//				for (int k = y; k < j; k++)
//					mergeMatrix[y][j] = min(mergeMatrix[y][j], mergeMatrix[y][k] + mergeMatrix[k + 1][j] + sum[j] - sum[y - 1]);
//			}
//		}
//		cout << mergeMatrix[1][size] << endl;
//	}
//	return 0;
//}

#include<cstdio>

int t, n, dp[501][501], opt[501][501], s[501];

int main() {
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", s + i);
            s[i] += s[i - 1];
            opt[i - 1][i] = i;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j + i <= n; j++) {
                dp[j][j + i] = 2e9;
                for (int k = opt[j][j + i - 1]; k <= opt[j + 1][j + i]; k++) {
                    if (dp[j][j + i] > dp[j][k] + dp[k][j + i]) {
                        dp[j][j + i] = dp[j][k] + dp[k][j + i];
                        opt[j][j + i] = k;
                    }
                }
                dp[j][j + i] += s[j + i] - s[j];
            }
        }
        printf("%d\n", dp[0][n]);
    }
    return 0;
}