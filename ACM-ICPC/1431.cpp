#include <bits/stdc++.h>

int n;
std::vector<std::string> v;

bool comp(std::string& x, std::string& y) {
    if (x.size() != y.size()) {
        return x.size() < y.size();
    } else {
        int xSum = 0, ySum = 0;

        for (int i = 0; i < x.size(); i++) {
            if (x[i] >= '0' && x[i] <= '9') {
                xSum += x[i] - '0';
            }
        }

        for (int i = 0; i < y.size(); i++) {
            if (y[i] >= '0' && y[i] <= '9') {
                ySum += y[i] - '0';
            }
        }

        if (xSum != ySum) {
            return xSum < ySum;
        } else {
            return x < y;
        }
    }
}

int main() {
    scanf("%d", &n);

    v.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }
}