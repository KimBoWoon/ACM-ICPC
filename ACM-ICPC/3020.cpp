#include <bits/stdc++.h>

int n, h, answer = 2e9, cnt;
std::vector<int> top, bottom;

/*
높이 1 일 때 부숴야 할 갯수 = (석순 총 갯수 - 석순 높이가 0 이하 갯수) + (종유석 총 갯수 - 종유석 높이가 H - 1 이하 갯수)
높이 2 일 때 부숴야 할 갯수 = (석순 총 갯수 - 석순 높이가 1 이하 갯수) + (종유석 총 갯수 - 종유석 높이가 H - 2 이하 갯수)
...
높이 H 일 때 부숴야 할 갯수 = (석순 총 갯수 - 석순 높이가 H - 1 이하 갯수) + (종유석 총 갯수 - 종유석 높이가 0 이하 갯수)
*/

int main() {
    scanf("%d %d", &n, &h);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0) {
            top.push_back(x);
        } else {
            bottom.push_back(x);
        }
    }

    std::sort(top.begin(), top.end());
    std::sort(bottom.begin(), bottom.end());

    for (int i = 1; i < h + 1; i++) {
        int x = top.size() - (lower_bound(top.begin(), top.end(), i) - top.begin());
        int y = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), h - i + 1) - bottom.begin());

        if (answer > x + y) {
            answer = x + y;
            cnt = 1;
        } else if (answer == x + y) {
            cnt++;
        }
    }

    printf("%d %d\n", answer, cnt);
}