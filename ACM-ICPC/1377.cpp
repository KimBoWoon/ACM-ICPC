#include <bits/stdc++.h>

int n, answer;
std::vector<std::pair<int, int> > v;

/*
버블 정렬은 어떤 수든 오른쪽으로는 무한정 움직일 수 있지만
왼쪽으로는 딱 한번만 움직인다
따라서 정렬 전의 인덱스 - 정렬 후의 인덱스의 가장 큰 값을 구하면 된다
*/
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