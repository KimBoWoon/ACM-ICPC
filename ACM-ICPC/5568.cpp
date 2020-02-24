#include <cstdio>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int card[11];
bool used[11];
vector<string> v;

void f(int i, int k, int n, string temp) {
    if (k == 0) {
        temp += to_string(card[i]);
        if (find(v.begin(), v.end(), temp) == v.end()) {
            v.push_back(temp);
        }
        return;
    }

    temp += to_string(card[i]);
    used[i] = true;
    k--;

    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            f(j, k, n, temp);
            used[j] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < n; i++) {
        memset(used, false, sizeof(used));
        string temp = "";
        f(i, k - 1, n, temp);
    }

    printf("%ld\n", v.size());
}