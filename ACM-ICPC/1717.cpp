//
// Created by null on 10/28/17.
//

//#define LOCAL
//
//#include <cstdio>

//int up[1000001], weight[1000001];
//int n, m;
//
//int SimpleFind(const int i) {
//    int root = i;
//
//    while (up[root] > 0) {
//        root = up[root];
//    }
//
//    return root;
//}
//
//void Union(const int i, const int j) {
//    int rooti = SimpleFind(i);
//    int rootj = SimpleFind(j);
//
//    if (weight[rooti] > weight[rootj]) {
//        up[rootj] = rooti;
//        weight[rooti] = weight[rooti] + weight[rootj];
//        weight[rootj] = 0;
//    }
//    else if (weight[rooti] < weight[rootj]) {
//        up[rooti] = rootj;
//        weight[rootj] = weight[rooti] + weight[rootj];
//        weight[rooti] = 0;
//    }
//    else if (weight[rooti] == weight[rootj]) {
//        if (rooti > rootj) {
//            up[rootj] = rooti;
//            weight[rooti] = weight[rooti] + weight[rootj];
//            weight[rootj] = 0;
//        }
//        else {
//            up[rooti] = rootj;
//            weight[rootj] = weight[rooti] + weight[rootj];
//            weight[rooti] = 0;
//        }
//    }
//}

//int main() {
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//    scanf("%d %d", &n, &m);
//
//    for (int i = 0; i <= n; i++) {
//        up[i] = i;
//    }
//
//    for (int i = 0; i < m; i++) {
//        int a, b, c;
//
//        scanf("%d %d %d", &a, &b, &c);
//
//        if (a == 0) {
//            Union(b, c);
//        } else if (a == 1) {
//            int x = SimpleFind(b);
//            int y = SimpleFind(c);
//
//            if (x == y) {
//                printf("YES\n");
//            } else {
//                printf("NO\n");
//            }
//        }
//    }
//}

#define LOCAL

#include <cstdio>

int n, m;
int p[1000001];

int find(int x) {
    if (x == p[x]) {
        return x;
    }
    else {
        return p[x] = find(p[x]);
    }
}

void uunion(int x, int y) {
    x = find(x);
    y = find(y);

    p[y] = x;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        if (a == 0) {
            uunion(b, c);
        } else if (a == 1) {
            int x = find(b);
            int y = find(c);

            if (x == y) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}