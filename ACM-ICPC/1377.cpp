#include <bits/stdc++.h>

int n, answer;
std::vector<std::pair<int, int> > v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(std::make_pair(x, i));
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        answer = std::max(answer, v[i].second - i);
    }

    printf("%d\n", answer + 1);
}