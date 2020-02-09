#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Point {
    int x, y;
} point;

int answer;
bool flag;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
string puyo[12];

bool comp(const point &x, const point &y) {
    if (x.y < y.y) {
        return true;
    } else if (x.y == y.y) {
        if (x.x < y.x) {
            return true;
        }
        return false;
    }
    return false;
}

void bfs() {
    while (true) {
        bool visited[12][6] = { false };
        vector<point> clear;

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (puyo[i][j] != '.') {
                    queue<point> q;
                    vector<point> v;
                    char c = puyo[i][j];
                    q.push({ i, j });
                    visited[i][j] = true;

                    while (!q.empty()) {
                        point p = q.front();
                        v.push_back({ p.x, p.y });
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = p.x + dx[i], ny = p.y + dy[i];

                            if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
                                if (puyo[nx][ny] == c && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({ nx, ny });
                                }
                            }
                        }
                    }

                    if (v.size() >= 4) {
                        while (!v.empty()) {
                            clear.push_back(v.front());
                            v.erase(v.begin());
                        }
                    }
                }
            }
        }
        if (!clear.empty()) {
            sort(clear.begin(), clear.end(), comp);
            for (int i = 0; i < clear.size(); i++) {
                for (int j = clear[i].x; j > 0; j--) {
                    puyo[j][clear[i].y] = puyo[j - 1][clear[i].y];
                }
                puyo[0][clear[i].y] = '.';
            }
            answer++;
        } else {
            break;
        }
    }
}

int main() {
    for (int i = 0; i < 12; i++) {
        cin >> puyo[i];
    }

    bfs();

    cout << answer << endl;
}