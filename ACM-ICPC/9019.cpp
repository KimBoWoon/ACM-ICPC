#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

int t, a, b;
bool visited[10001];

string bfs() {
    queue<pair<int, string> > q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty()) {
        int temp = 0;
        pair<int, string> n = q.front();
        q.pop();

        if (n.first == b) {
            return n.second;
        }

        temp = (n.first * 2) % 10000;
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({ temp, n.second + 'D' });
        }

        temp = (n.first - 1 < 0) ? 9999 : n.first - 1;
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({ temp, n.second + 'S' });
        }

        temp = (n.first % 1000) * 10 + n.first / 1000;
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({ temp, n.second + 'L' });
        }

        temp = (n.first % 10) * 1000 + (n.first / 10);
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({ temp, n.second + 'R' });
        }
    }
}

int main() {
    cin >> t;
    // scanf("%d", &t);

    while (t--) {
        // scanf("%d %d", &a, &b);

        // printf("%s\n", bfs().c_str());

        memset(visited, false, sizeof(visited));

        cin >> a >> b;

        cout << bfs() << endl;
    }
}