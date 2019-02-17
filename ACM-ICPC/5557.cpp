#include <cstdio>
using namespace std;

int n;
int arr[101];
long result[101][21];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    result[1][arr[1]] = 1;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (result[i][j] > 0) {
                if (j + arr[i + 1] >= 0 && j + arr[i + 1] <= 20) {
                    result[i + 1][j + arr[i + 1]] += result[i][j];
                }
                if (j - arr[i + 1] >= 0 && j - arr[i + 1] <= 20) {
                    result[i + 1][j - arr[i + 1]] += result[i][j];
                }
            }
        }
    }

    printf("%ld\n", result[n - 1][arr[n]]);
}