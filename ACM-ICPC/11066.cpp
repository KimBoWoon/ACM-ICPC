#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int testCase, size;
int file[501] = { 0 };
int sum[501] = { 0 };
int dp[501][501] = { 0 };

int main() {
    scanf("%d", &testCase);

	while (testCase--) {
        scanf("%d", &size);

		memset(file, 0, sizeof(int) * 501);
		memset(sum, 0, sizeof(int) * 501);

		for (int i = 0; i < size; i++) {
            scanf("%d", &file[i]);
			sum[i + 1] = sum[i] + file[i];
		}

		for (int x = 1; x < size; x++) {
			for (int y = 1; y <= size - x; y++) {
				int j = y + x;

				if (j > size) {
					break;
                }

				dp[y][j] = 2e9;

				for (int k = y; k < j; k++) {
					dp[y][j] = min(dp[y][j], dp[y][k] + dp[k + 1][j] + sum[j] - sum[y - 1]);
                }
			}
		}

        printf("%d\n", dp[1][size]);
	}

	return 0;
}

// int main() {
//     scanf("%d", &testCase);

//     while (testCase--) {
//         int opt[501][501] = { 0 };
//         scanf("%d", &size);

//         for (int i = 1; i <= size; i++) {
//             scanf("%d", &file[i]);

//             file[i] += file[i - 1];
//             opt[i - 1][i] = i;
//         }

//         for (int i = 2; i <= size; i++) {
//             for (int j = 0; j + i <= size; j++) {
//                 dp[j][j + i] = 2e9;

//                 for (int k = opt[j][j + i - 1]; k <= opt[j + 1][j + i]; k++) {
//                     if (dp[j][j + i] > dp[j][k] + dp[k][j + i]) {
//                         dp[j][j + i] = dp[j][k] + dp[k][j + i];
//                         opt[j][j + i] = k;
//                     }
//                 }

//                 dp[j][j + i] += file[j + i] - file[j];
//             }
//         }

//         printf("%d\n", dp[0][size]);
//     }

//     return 0;
// }