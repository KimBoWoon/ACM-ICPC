#include <cstdio>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n, sum = 0;
        vector<int> v;

        scanf("%d", &n);

        if (n == -1) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                v.push_back(i);
            }
        }

        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }

        printf("%d", n);
        if (sum == n) {
            printf(" =");
            for (int i = 0; i < v.size(); i++) {
                if (i == v.size() - 1) {
                    printf(" %d\n", v[i]);
                } else {
                    printf(" %d +", v[i]);
                }
            }
        } else {
            printf(" is NOT perfect.\n");
        }
    }
}