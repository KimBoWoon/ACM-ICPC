#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int n;
char arr[10];
vector<string> answer;
bool visited[10];

void check(char *arr, int n, int x, string result) {
    if (n == x) {
        answer.push_back(result);
    }

    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            visited[i] = true;

            if (result.empty()) { // 비어있다면 시작 숫자 선택
                result.push_back(i + '0');
                check(arr, n, x, result);
                result.pop_back();
            } else { // 부등호에 맞게 숫자 넣기
                if (arr[x] == '<') {
                    if (result.back() - '0' < i) {
                        result.push_back(i + '0');
                        check(arr, n, x + 1, result);
                        result.pop_back();
                    }
                } else {
                    if (result.back() - '0' > i) {
                        result.push_back(i + '0');
                        check(arr, n, x + 1, result);
                        result.pop_back();
                    }
                }
            }

            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    check(arr, n, 0, "");

    printf("%s\n%s\n", answer.back().c_str(), answer.front().c_str());
}