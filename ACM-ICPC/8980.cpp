#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Box {
    int from, to, c;
} box;

int n, c, m;
int answer;
int capacity[2001];
vector<box> v;

bool comp(const box &x, const box &y) {
    if (x.to == y.to) {
        return x.from < y.from;
    }
    return x.to < y.to;
}

int main() {
    scanf("%d %d %d", &n, &c, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({ a, b, c });
    }

    sort(v.begin(), v.end(), comp);

    // for (int i = 0; i < v.size(); i++) {
    //     printf("%d %d %d\n", v[i].from, v[i].to, v[i].c);
    // }

    for (int i = 0; i < m; i++) {
        int boxCount = 0;

        for (int j = v[i].from; j < v[i].to; j++) {
            boxCount = max(boxCount, capacity[j]);
        }
        int leftSpace = min(v[i].c, c - boxCount);
        answer += leftSpace;
        for (int j = v[i].from; j < v[i].to; j++) {
            capacity[j] += leftSpace;
        }
    }

    printf("%d\n", answer);
}