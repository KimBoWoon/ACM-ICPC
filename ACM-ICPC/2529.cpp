#include <iostream>
#include <string>
using namespace std;

int k;
string arr[10], answer;
bool visited[10];

void dfs(int v, int cnt, string str) {
    if (cnt == k) {
        answer += str;
    } else {
        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                if (arr[cnt].compare("<") == 0) {
                    if (v >= i) {
                        continue;
                    }
                } else {
                    if (v <= i) {
                            continue;
                    }
                }
                visited[i] = true;
                dfs(i, cnt + 1, str + to_string(i));
            }
        }
    }
    visited[v] = false;
}

int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        visited[i] = true;
        dfs(i, 0, to_string(i));
    }

    for (int i = 0; i <= k; i++) {
        cout << answer[i];
    }
    cout << endl;

    for (int i = answer.size() - k - 1; k >= 0; k--, i++) {
        cout << answer[i];
    }
    cout << endl;
}