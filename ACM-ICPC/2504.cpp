#include <cstdio>
#include <stack>
#include <string>
using namespace std;

char str[31];
long long answer = 0;
bool flag;
stack<string> s;

int main() {
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        int temp = 0;

        if (str[i] == '(') {
            s.push("(");
        } else if (str[i] == '[') {
            s.push("[");
        } else {
            if (s.empty()) {
                printf("0\n");
                return 0;
            }
            if (str[i] == ')') {
                if (s.top() == "(") {
                    s.pop();
                    s.push("2");
                } else {
                    while (!s.empty()) {
                        if (s.top() == "[") {
                            printf("0\n");
                            return 0;
                        } else if (s.top() == "(") {
                            s.pop();
                            temp *= 2;
                            s.push(to_string(temp));
                            break;
                        } else {
                            temp += stoi(s.top());
                            s.pop();
                        }
                    }
                }
            } else {
                if (s.top() == "[") {
                    s.pop();
                    s.push("3");
                } else {
                    while (!s.empty()) {
                        if (s.top() == "(") {
                            printf("0\n");
                            return 0;
                        } else if (s.top() == "[") {
                            s.pop();
                            temp *= 3;
                            s.push(to_string(temp));
                            break;
                        } else {
                            temp += stoi(s.top());
                            s.pop();
                        }
                    }
                }
            }
        }
    }

    while (!s.empty()) {
        if (s.top() == "(" || s.top() == "[" || s.top() == ")" || s.top() == "]") {
            printf("0\n");
            return 0;
        }
        answer += stoi(s.top());
        s.pop();
    }

    printf("%lld\n", answer);

    // for (int i = 0; str[i] != '\0'; i++) {
    //     if (str[i] == '(') {
    //         temp *= 2;
    //         s.push(str[i]);
    //     } else if (str[i] == '[') {
    //         temp *= 3;
    //         s.push(str[i]);
    //     } else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
    //         flag = true;
    //         break;
    //     } else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
    //         flag = true;
    //         break;
    //     } else if (str[i] == ')') {
    //         if (str[i - 1] == '(') {
    //             answer += temp;
    //         }
    //         s.pop();
    //         temp /= 2;
    //     } else if (str[i] == ']') {
    //         if (str[i - 1] == '[') {
    //             answer += temp;
    //         }
    //         s.pop();
    //         temp /= 3;
    //     }
    // }

    // if (!s.empty() || flag) {
    //     printf("0\n");
    // } else {
    //     printf("%lld\n", answer);
    // }
}