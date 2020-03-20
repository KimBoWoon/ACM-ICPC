#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int dfs(int idx) {
    int i, answer = 0;

    for (i = idx; i < s.size(); i++) {
        if (s[i] == ')') {
            break;
        } else if (s[i + 1] == '(') {
            answer += dfs(i + 2) * (s[i] - '0'); // 단어 반복
            i = n; // 다음 확인 해야할 위치 확인
        } else {
            answer++; // 단어 추가
        }
    }

    n = i; // 위치 저장
    
    return answer;
}

int main() {
    cin >> s;

    cout << dfs(0) << endl;
}

// #include <iostream>
// using namespace std;

// string str, temp, answer;

// int main() {
//     cin >> str;

//     for (int i = str.size() - 1; i >= 0; i--) {
//         if (str[i] == ')') {
//             continue;
//         } else if (str[i] >= '0' && str[i] <= '9') {
//             answer += str[i];
//         } else if (str[i] == '(') {
//             temp = answer;
//             for (int j = 1; j < str[i - 1] - '0'; j++) {
//                 answer += temp;
//             }
//             temp.clear();
//             i--;
//         }
//     }

//     if (!temp.empty()) {
//         answer += temp;
//     }

//     cout << answer.size() << endl;
// }