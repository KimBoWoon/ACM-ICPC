#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

string n;
int size, k;

int toInt(string s) {
    int result = 0, mul = 1;

    for (int i = s.size() - 1; i > -1; i--) {
        result += (s[i] - '0') * mul;
        mul *= 10;
    }

    return result;
}

void bfs() {
    queue<string> q;
    int count = 0, answer = 0;

    q.push(n);

    while (!q.empty() && count < k) {
        int qSize = q.size();
        set<string> visited;

        while (qSize--) {
            string now = q.front();
            q.pop();

            for (int i = 0; i < n.size() - 1; i++) {
                for (int j = i + 1; j < n.size(); j++) {
                    // 숫자가 0으로 시작 할 수 없다
                    if (i == 0 && now[j] == '0') {
                        continue;
                    }

                    // 자리 바꾸기
                    swap(now[i], now[j]);
                    if (!visited.count(now)) {
                        // k번 바꾼 경우 최대값 찾기
                        if (count == k - 1) {
                            answer = max(answer, toInt(now));
                        }

                        // 다음 수 큐에 넣기
                        q.push(now);
                        // 방문 기록 남기기
                        visited.insert(now);
                    }
                    swap(now[i], now[j]);
                }
            }
        }
        count++;
    }

    if (count != k) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }
}

int main() {
    cin >> n >> k;

    // 한 자리 수거나 숫자가 0으로 시작할 수 없다
    if (n.size() == 1 || (n.size() == 2 && n[n.size() - 1] == '0')) {
        cout << -1 << endl;
    } else {
        bfs();
    }
}